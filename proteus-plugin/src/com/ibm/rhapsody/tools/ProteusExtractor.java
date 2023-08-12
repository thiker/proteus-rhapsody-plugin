package com.ibm.rhapsody.tools;

import java.nio.file.Files;
import java.nio.file.Path;
import java.io.File;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.Consumer;

import org.eclipse.paho.client.mqttv3.IMqttMessageListener;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.MqttPersistenceException;
import org.eclipse.paho.client.mqttv3.MqttSecurityException;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;
import org.json.JSONObject;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPClass;
import com.telelogic.rhapsody.core.IRPCollection;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPGraphElement;
import com.telelogic.rhapsody.core.IRPGraphNode;
import com.telelogic.rhapsody.core.IRPGraphicalProperty;
import com.telelogic.rhapsody.core.IRPImageMap;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPPackage;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.IRPStatechart;
import com.telelogic.rhapsody.core.IRPUnit;
import com.telelogic.rhapsody.core.RPGraphicalProperty;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

/**
 * Extractor class for Proteus which is used to extract, convert and communicate the existing 2D system models to 3DML formatted data.
 * This data is then sent to the broker so it can be visualized by Proteus in Unity.
 * @author thijskoenraadt
 *
 */
public class ProteusExtractor {
	ProteusRhapsodyAppListener appListener = null;
	static IRPApplication irpApp = null;
	static IRPProject irpPrj = null;
	static MqttClient mqttClient = null;
	static int mqttQos = 1;
	
	/**
	 * Default broker IP. This IP will be overriden with the value set in the Proteus communication object in the Rhapsody project that the plugin is attached to.
	 */
	static String mqttBroker = "tcp://127.0.0.1:1883";
	
	/**
	 * The ID that the proteus plugin will use for its MQTT client. 
	 */
	static String mqttClientId = "IBMRhapsody";
	
	static Path tempDirPath = null;

	private static ProteusExtractor INSTANCE;

	private ProteusExtractor() {
	}

	/**
	 * Gets the singleton instance of the ProteusExtractor.
	 * @return Singleton instance of the ProteusExtractor.
	 */
	public static ProteusExtractor getInstance() {
		if (INSTANCE == null) {
			INSTANCE = new ProteusExtractor();
		}
		return INSTANCE;
	}
	
	/**
	 * Gets the diagram of the element that is currently selected and opens this diagram in a viewer of Proteus in Unity.
	 */
	public void OpenDiagramOfSelectedElement() {
		JSONObject data = new JSONObject();
		String[] rootNodeIds = new String[] {irpApp.getDiagramOfSelectedElement().getGUID()};
		data.put("RootNodeIds", rootNodeIds);
		sendMqttMessage(data, "proteus/data/create/viewers/");
	}
	
	/**
	 * Refreshes the ProteusPlugin, establishes the MQTT communication and extracts all models once so the all 3DML formatted data is sent once.
	 */
	public void refresh() {
		dispose();
		
		if (init()) {
			extractAll();
			javax.swing.JOptionPane.showMessageDialog(null, "Refreshed Proteus.", "ProteusExtractor", javax.swing.JOptionPane.PLAIN_MESSAGE);
		} else {
			javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Something went wrong when trying to refresh Proteus.", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
		}
	}

	/**
	 * Initialize the ProteusExtractor. Get a reference to the active IBM-Rhapsody application and establish an MQTT connection. Once this connection is established, the plugin will send once all extracted 3DML formatted data.
	 * @return whether the ProteusExtractor was successfully initialized.
	 */
	private boolean init() {
		// Get the rhapsody application
		if (irpApp == null) {
			try {
				irpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
			} catch (Exception e) {
				e.printStackTrace();
				javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Can not find active IBM Rhapsody Application", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
				return false;
			}
		}
		
		// Create a listener for the app and connect it.
		appListener = new ProteusRhapsodyAppListener();
		appListener.connect(irpApp);
		
		// Get the active project.
		try {
			irpPrj = irpApp.activeProject();
		} catch (Exception e) {
			e.printStackTrace();
			javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Can not find active IBM Rhapsody project.", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		// Get mqtt connection details. 
		IRPClass connClass = irpPrj.findClass(("ProteusComms"));
		try {
			mqttBroker = connClass.findAttribute("ADDRESS").getDefaultValue().replaceAll("\"", "");
			System.out.println("Mqtt broker set to:" + mqttBroker);
		} catch(Exception e) {}
		try {
			mqttQos = Integer.parseInt(connClass.findAttribute("QOS").getDefaultValue());
			System.out.println("Mqtt QOS set to:" + mqttQos);
		} catch(Exception e) {}
		
		// Listen to element changes
		irpPrj.setNotifyPluginOnElementsChanged(1);

		// Create temp directory
		try {
			tempDirPath = Files.createTempDirectory("proteus");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}
		
		if (initClient()) {
			extractAll();
		} else {
			javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Failed to connect MQTT.", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
			return false;
		}
		return true;
	}

	/**
	 * Initialises the MQTT client and connection.
	 * @return whether the MQTT client was successfully initialized.
	 */
	private boolean initClient() {
		MemoryPersistence persistence = new MemoryPersistence();
		MqttConnectOptions connOpts = new MqttConnectOptions();
		connOpts.setCleanSession(true);

		// Create MQTT Client
		try {
			mqttClient = new MqttClient(mqttBroker, mqttClientId, persistence);
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Failed to create MQTT client.", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
			return false;
		}

		// Connect to Broker
		System.out.println("Connecting to broker: " + mqttBroker);
		try {
			mqttClient.connect(connOpts);
			System.out.println("Connected");
		} catch (MqttSecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("MQTT Connection Init failed.");
			return false;
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("MQTT Connection Init failed.");
			return false;
		}
		
		// Subscribe to actions topic
		try {
			mqttClient.subscribe("proteus/actions/extern/selection", new PTMqttMessageListener());
		} catch (MqttException e) {
			System.out.println("MQTT Subscription failed.");
			e.printStackTrace();
			return false;
		}
		return true;
	}

	/**
	 * Sends an MQTT message to the broker.
	 * @param data the json data to send.
	 * @param topic the topic to send the data to.
	 */
	private void sendMqttMessage(JSONObject data, String topic) {
		// Create message
		MqttMessage message = new MqttMessage();
		message.setPayload(data.toString().getBytes());
		message.setQos(mqttQos);

		// Send update
		try {
			mqttClient.publish(topic, message);
		} catch (MqttPersistenceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/***
	 * Generates a message that contains the 3DML formatted data of a node and sends it.
	 * 
	 * @param node the node to send the data for.
	 */
	private void sendNodeDataUpdate(IRPUnit node) {
		IRPCollection modelElements = null;
		Set<String> modelElementsGuids = new HashSet<>();
		Set<String> nodeEdges = new HashSet<>();
		Set<String> relatedDiagramsGuids = Collections.emptySet();

		JSONObject nodeData = new JSONObject();

		// Generate edge data and get model elements guids.
		if (node instanceof IRPDiagram) {
			IRPDiagram nodeAsDiagram = (IRPDiagram) node;
			relatedDiagramsGuids = getRelatedDiagramsOfDiagram(nodeAsDiagram);
			modelElements = nodeAsDiagram.getElementsInDiagram();
		} else if (node instanceof IRPStatechart) {
			IRPStatechart nodeAsStatechart = (IRPStatechart) node;
			modelElements = nodeAsStatechart.getElementsInDiagram();
		}

		// Get the ids of all model elements in the diagram.
		if (modelElements != null) {
			for (IRPModelElement element : (List<IRPModelElement>) modelElements.toList()) {
				modelElementsGuids.add(element.getGUID());
			}
		}

		// Create edges for each related diagram and send this edge update.
		for (String diagramGuid : relatedDiagramsGuids) {
			// Create edge update.
			JSONObject edgeData = new JSONObject();
			String edgeId = "PT_EDGE " + node.getGUID() + " " + diagramGuid;

			edgeData.put("Id", edgeId);
			edgeData.put("Source", node.getGUID());
			edgeData.put("Target", diagramGuid);

			// Send edge update
			sendMqttMessage(edgeData, "proteus/data/update/3dml/edges/" + edgeId);

			nodeEdges.add(edgeId);
		}

		// Generate node data
		nodeData.put("Id", node.getGUID());
		nodeData.put("Name", node.getName());
		nodeData.put("MetaClass", node.getMetaClass());
		nodeData.put("DisplayName", node.getDisplayName());
		nodeData.put("Description", node.getDescriptionPlainText());
		nodeData.put("Edges", nodeEdges.toArray());
		nodeData.put("ModelElements", modelElementsGuids.toArray());

		sendMqttMessage(nodeData, "proteus/data/update/3dml/nodes/" + node.getGUID().toString());
	}

	/**
	 * Generate a message that contains the image data of a node and sends it.
	 * 
	 * @param node the node for which the image should be sent.
	 */
	private void sendNodeImageUpdate(IRPUnit node) {
		System.out.println("Processing image update for node " + node.getDisplayName() + "..");
		byte[] msgImageContent = new byte[0];

		if (node != null) {
			System.out.println("Generating diagram image...");
			IRPCollection imageMaps = irpApp.createNewCollection();
			Path imgPath = tempDirPath.resolve(node.getGUID() + ".jpeg");

			// Generate image
			if (node instanceof IRPDiagram) {
				((IRPDiagram) node).getPictureAs(imgPath.toString(), "JPEG", 1, imageMaps);
			} else if (node instanceof IRPStatechart) {
				((IRPStatechart) node).getPictureAs(imgPath.toString(), "JPEG", 1, imageMaps);
			}

			// Get image as bytes
			try {
				msgImageContent = Files.readAllBytes(imgPath);
				System.out.println("Image to bytes completed.");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		System.out.println("Creating image update message..");
		// Create message
		MqttMessage message = new MqttMessage();
		message.setPayload(msgImageContent);
		message.setQos(mqttQos);

		// Send update
		try {
			mqttClient.publish("proteus/data/update/3dml/images/" + node.getGUID().toString(), message);
			System.out.println("Image update sent of length " + msgImageContent.length);
		} catch (MqttPersistenceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * Sends a node update for a class model element.
	 * @param element the class model element to send.
	 * @param relatedDiagramGuids A set of GUIDs that the diagram is related to.
	 */
	private void sendClassModelElementUpdate(IRPClass element, Set<String> relatedDiagramGuids) {
		if (element == null) {
			return;
		}

		JSONObject data = new JSONObject();

		data.put("Id", element.getGUID());
		data.put("MetaClass", element.getMetaClass());
		data.put("Name", element.getName());
		data.put("Description", element.getDescription());
		data.put("DisplayName", element.getDisplayName());
		data.put("RelatedNodes", relatedDiagramGuids.toArray());

		System.out.println("Creating model element update for node " + element.getDisplayName() + "..");
		sendMqttMessage(data, "proteus/data/update/3dml/model-elements/" + element.getGUID().toString());

	}

	/******************************************************
	 * Helpers
	 ******************************************************/

	/**
	 * Get the diagrams that are related to the given diagram.
	 * 
	 * @param diagram the parent diagram
	 * @return related diagrams
	 */
	private Set<String> getRelatedDiagramsOfDiagram(IRPDiagram diagram) {
		IRPCollection diagElements = diagram.getElementsInDiagram();

		Set<String> linkedDiagrams = new HashSet<>();

		// Add the GUIDs of the related diagrams
		for (int i = 1; i <= diagElements.getCount(); i++) {
			IRPModelElement element = (IRPModelElement) diagElements.getItem(i);
			IRPDiagram mainDiagram = element.getMainDiagram();

			if (mainDiagram != null) {
				// Prevent self loops
				if (!diagram.getGUID().equals(mainDiagram.getGUID())) {
					linkedDiagrams.add(mainDiagram.getGUID());
				}
			}

		}

		return linkedDiagrams;
	}

	/******************************************************
	 * 
	 * EXTRACTION / GENERATION
	 *
	 ******************************************************/

	/**
	 * Starts extracting all the data for Proteus. Used internally by the extractor during a refresh or initialization.
	 */
	private void extractAll() {
		IRPCollection packages = irpPrj.getPackages();

		for (IRPPackage irpPackage : (List<IRPPackage>) packages.toList()) {
			extractClasses(irpPackage);
			extractObjectModelDiagrams(irpPackage);
		}
	}
	
	/**
	 * Extracts a model element and converts it to 3DML formatted data that is sent to the MQTT broker so it can be used by Proteus in Unity.
	 * 
	 * The most important function of the extractor. This function will be called whenever a model element changes.
	 * This function can be extended / modified to add support for additional types of classes or objects to extract.
	 * This can be accomplished by implementing these extraction functions and changing the switch statement.
	 * @param el the model element to extract.
	 */
	public void extractModelElement(IRPModelElement el) {
		if (el == null) {
			return;
		}
		
		String metaClass = el.getMetaClass();
		switch(metaClass) {
			case "Class": {
				extractClass((IRPClass)el);
				break;
			}
			case "ObjectModelDiagram": {
				extractDiagram((IRPUnit)el);
			}
		}
	}

	/**
	 * Extracts all object model diagrams for a given package..
	 * Used internally by the extractor during a refresh or initialization.
	 * 
	 * @param irpPackage the package to get the model diagrams from.
	 */
	private void extractObjectModelDiagrams(IRPPackage irpPackage) {
		IRPCollection omdCollection = irpPackage.getObjectModelDiagrams();

		for (int i = 1; i <= omdCollection.getCount(); i++) {
			IRPDiagram diagram = (IRPDiagram) omdCollection.getItem(i);
			extractDiagram(diagram);
		}
	}

	/**
	 * Extracts all classes model elements for a given package.
	 * Used internally by the extractor during a refresh or initialization.
	 * 
	 * @param irpPackage the package to extract the data from.
	 */
	private void extractClasses(IRPPackage irpPackage) {
		IRPCollection irpClasses = irpPackage.getClasses();

		for (IRPClass irpClass : (List<IRPClass>) irpClasses.toList()) {
			extractClass(irpClass);
		}
	}

	/**
	 * Extracts a class and sends the update.
	 * @param irpClass
	 * */
	private void extractClass(IRPClass irpClass) {
		IRPCollection stateCharts = irpClass.getBehavioralDiagrams();

		Set<String> relatedDiagramsGuids = new HashSet<>();
		for (IRPStatechart statechart : (List<IRPStatechart>) stateCharts.toList()) {
			relatedDiagramsGuids.add(statechart.getGUID());
			extractDiagram((IRPUnit) statechart);
		}

		sendClassModelElementUpdate(irpClass, relatedDiagramsGuids);		
	}
	
	/**
	 * Extracts a diagram node and sends the update.
	 * @param node the node to extract.
	 */
	private void extractDiagram(IRPUnit node) {
		sendNodeDataUpdate(node);
		sendNodeImageUpdate(node);
	}
	
	/**
	 * Disposes the extractor, clears the images that were generated and closes the MQTT communication.
	 */
	public void dispose() {
		if (appListener != null) {
			appListener.disconnect();
		}
		if (mqttClient != null) {
			try {
				mqttClient.close();
			} catch (MqttException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			mqttClient = null;
		}

		if (tempDirPath != null) {
			File directoryToBeDeleted = new File(tempDirPath.toString());
			File[] allContents = directoryToBeDeleted.listFiles();
			if (allContents != null) {
				for (File file : allContents) {
					file.delete();
				}
			}
			directoryToBeDeleted.delete();
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		// Setup IBMRhapsody API
		ProteusExtractor.getInstance().refresh();
	}

}
