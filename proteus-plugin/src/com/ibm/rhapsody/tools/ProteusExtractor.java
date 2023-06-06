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

public class ProteusExtractor {
	ProteusRhapsodyAppListener appListener = null;
	static IRPApplication irpApp = null;
	static IRPProject irpPrj = null;
	static MqttClient mqttClient = null;
	static int mqttQos = 1;
	static String mqttBroker = "tcp://127.0.0.1:1883";
	static String mqttClientId = "IBMRhapsody";
	static Path tempDirPath = null;

	private static ProteusExtractor INSTANCE;

	private ProteusExtractor() {
	}

	public static ProteusExtractor getInstance() {
		if (INSTANCE == null) {
			INSTANCE = new ProteusExtractor();
		}
		return INSTANCE;
	}

	public void refresh() {
		dispose();
		if (init()) {
			extractAll();
			javax.swing.JOptionPane.showMessageDialog(null, "Refreshed Proteus.", "ProteusExtractor", javax.swing.JOptionPane.PLAIN_MESSAGE);
		} else {
			javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Something went wrong when trying to refresh Proteus.", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
		}
	}

	private boolean init() {
		if (irpApp == null) {
			try {
				irpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
			} catch (Exception e) {
				e.printStackTrace();
				javax.swing.JOptionPane.showMessageDialog(null, "ERROR: Can not find active IBM Rhapsody Application", "ProteusExtractor", javax.swing.JOptionPane.ERROR_MESSAGE);
				return false;
			}
		}
		
		appListener = new ProteusRhapsodyAppListener();
		appListener.connect(irpApp);
		
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
	 * Generates a message that contains the data of a node.
	 * 
	 * @param node
	 * @return message with node data
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

		for (String diagramGuid : relatedDiagramsGuids) {
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
	 * Generate a message that contains the image data of a node.
	 * 
	 * @param node
	 * @return message with node image data
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
	 * 
	 * Helpers
	 *
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
	 * Start extracting the data for Proteus
	 */
	private void extractAll() {
		IRPCollection packages = irpPrj.getPackages();

		for (IRPPackage irpPackage : (List<IRPPackage>) packages.toList()) {
			extractClasses(irpPackage);
			extractObjectModelDiagrams(irpPackage);
		}
	}
	
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
	 * Extract all object model diagrams from the project.
	 * 
	 * @param irpPackage
	 */
	private void extractObjectModelDiagrams(IRPPackage irpPackage) {
		IRPCollection omdCollection = irpPackage.getObjectModelDiagrams();

		for (int i = 1; i <= omdCollection.getCount(); i++) {
			IRPDiagram diagram = (IRPDiagram) omdCollection.getItem(i);
			extractDiagram(diagram);
		}
	}

	/**
	 * Extracts all classes model elements from the project.
	 */
	private void extractClasses(IRPPackage irpPackage) {
		IRPCollection irpClasses = irpPackage.getClasses();

		for (IRPClass irpClass : (List<IRPClass>) irpClasses.toList()) {
			extractClass(irpClass);
		}
	}

	/*
	 * Extracts a class and sends the update
	 * */
	public void extractClass(IRPClass irpClass) {
		IRPCollection stateCharts = irpClass.getBehavioralDiagrams();

		Set<String> relatedDiagramsGuids = new HashSet<>();
		for (IRPStatechart statechart : (List<IRPStatechart>) stateCharts.toList()) {
			relatedDiagramsGuids.add(statechart.getGUID());
			extractDiagram((IRPUnit) statechart);
		}

		sendClassModelElementUpdate(irpClass, relatedDiagramsGuids);		
	}

	private void extractDiagram(IRPUnit node) {
		sendNodeDataUpdate(node);
		sendNodeImageUpdate(node);
	}
	
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
