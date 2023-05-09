package com.ibm.rhapsody.tools;

import java.nio.file.Files;
import java.nio.file.Path;
import java.io.File;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.Consumer;

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
import com.telelogic.rhapsody.core.RPGraphicalProperty;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

public class ProteusExtractor {
	static IRPApplication irpApp;
	static IRPProject irpPrj;
	static MqttClient mqttClient;
	static int mqttQos = 1;
	static String mqttBroker = "tcp://localhost:1883";
	static String mqttClientId = "IBMRhapsody";
	static Path tempDirPath = null;

	/***
	 * Generates a message that contains the data of a node.
	 * 
	 * @param node
	 * @return message with node data
	 */
	static void sendNodeDataUpdate(IRPDiagram node) {
		JSONObject nodeData = new JSONObject();
		// Generate edge data
		Set<String> relatedDiagramsGuids = getRelatedDiagramsOfDiagram(node);
		
		Set<String> nodeEdges = new HashSet<>();
		
		for (String diagramGuid : relatedDiagramsGuids) {
			JSONObject edgeData = new JSONObject();
			String edgeId = "PT_EDGE " + node.getGUID()  + " " + diagramGuid;
			
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
		nodeData.put("DisplayName", node.getDisplayName());
		nodeData.put("Description", node.getDescriptionPlainText());
		nodeData.put("Edges", nodeEdges.toArray());

		sendMqttMessage(nodeData, "proteus/data/update/3dml/nodes/" + node.getGUID().toString());

	}
	
	static void sendMqttMessage(JSONObject data, String topic) {
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

	/**
	 * Generate a message that contains the image data of a node.
	 * 
	 * @param node
	 * @return message with node image data
	 */
	static void sendNodeImageUpdate(IRPDiagram node) {
		System.out.println("Processing image update for node "+ node.getDisplayName() + "..");
		byte[] msgImageContent = new byte[0];

		if (node != null) {
			System.out.println("Generating diagram image...");
			IRPCollection imageMaps = irpApp.createNewCollection();
			Path imgPath = tempDirPath.resolve(node.getGUID() + ".jpeg");
			
			// Generate image
			node.getPictureAs(imgPath.toString(), "JPEG", 1, imageMaps);
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
			System.out.println("Image update sent of length "+ msgImageContent.length);
		} catch (MqttPersistenceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	/**
	 * Initialises the MQTT client and connection.
	 */
	static void initClient() {
		MemoryPersistence persistence = new MemoryPersistence();
		MqttConnectOptions connOpts = new MqttConnectOptions();
		connOpts.setCleanSession(true);

		// Create MQTT Client
		try {
			mqttClient = new MqttClient(mqttBroker, mqttClientId, persistence);
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		// Connect to Broker
		System.out.println("Connecting to broker: " + mqttBroker);
		try {
			mqttClient.connect(connOpts);
			System.out.println("Connected");
		} catch (MqttSecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Connection failed");
		} catch (MqttException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Connection failed");
		}

	}

	/**
	 * Get the diagrams that are related to the given diagram.
	 * @param diagram the parent diagram
	 * @return related diagrams
	 */
	static Set<String> getRelatedDiagramsOfDiagram(IRPDiagram diagram) {
		IRPCollection diagElements = diagram.getElementsInDiagram();
		
		Set<String> linkedDiagrams = new HashSet<>();
		
		// Add the GUIDs of the related diagrams
		for (int i = 1; i <= diagElements.getCount(); i++) {
			IRPModelElement element = (IRPModelElement)diagElements.getItem(i);
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
	
	static void generate() {
		// Object Model Diagrams
		IRPCollection allColl = irpPrj.getNestedElementsByMetaClass("ObjectModelDiagram", 1);

		for (int i = 1; i <= allColl.getCount(); i++) {
			IRPDiagram diagram = (IRPDiagram) allColl.getItem(i);
			System.out.println("Sending update for element" + diagram.getDisplayName());
			
			sendNodeDataUpdate(diagram);
			sendNodeImageUpdate(diagram);
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		// Setup IBMRhapsody API
		irpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
		irpPrj = irpApp.activeProject();
		
		// Create temp directory
		tempDirPath = Files.createTempDirectory("proteus");
		// Delete temp on exit
	    Runtime.getRuntime().addShutdownHook(new Thread(new Runnable() {
	        public void run() {
	        	File directoryToBeDeleted = new File(tempDirPath.toString());
	    	    File[] allContents = directoryToBeDeleted.listFiles();
	    	    if (allContents != null) {
	    	        for (File file : allContents) {
	    	            file.delete();
	    	        }
	    	    }
	    	    directoryToBeDeleted.delete();
	        }
	    }, "Shutdown-thread"));
		
		
		initClient();

		generate();
		
		//Exit so that shutdown routine gets called during testing in eclipse
		System.exit(0);
	}

}
