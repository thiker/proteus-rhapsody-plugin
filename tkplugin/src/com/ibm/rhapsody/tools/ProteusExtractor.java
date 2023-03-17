package com.ibm.rhapsody.tools;

import java.nio.file.Files;
import java.io.File;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
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

	/***
	 * Generates a message that contains the data of a node.
	 * 
	 * @param node
	 * @return message with node data
	 */
	static void sendNodeDataUpdate(IRPModelElement node) {
		JSONObject nodeData = new JSONObject();
		nodeData.put("Id", node.getGUID().toString());
		nodeData.put("Name", node.getName());
		nodeData.put("DisplayName", node.getDisplayName());
		nodeData.put("Description", node.getDescriptionPlainText());

		// Create message
		MqttMessage message = new MqttMessage();
		message.setPayload(nodeData.toString().getBytes());
		message.setQos(mqttQos);

		// Send update
		try {
			mqttClient.publish("proteus/data/update/3dml/nodes/" + node.getGUID().toString(), message);
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
	static void sendNodeImageUpdate(IRPModelElement node) {
		IRPDiagram diagram = node.getMainDiagram();
		byte[] msgImageContent = new byte[0];

		if (diagram != null) {
			IRPCollection imageMaps = irpApp.createNewCollection();
			String filePath = System.getProperty("java.io.tmpdir").toString() + "/proteus/generated/images/"
					+ node.getGUID() + ".jpeg";

			// Generate image
			diagram.getPictureAs(filePath, "JPEG", 1, imageMaps);
			File fi = new File(filePath);

			// Get image as bytes
			try {
				msgImageContent = Files.readAllBytes(fi.toPath());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		// Create message
		MqttMessage message = new MqttMessage();
		message.setPayload(msgImageContent);
		message.setQos(mqttQos);

		// Send update
		try {
			mqttClient.publish("proteus/data/update/3dml/images/" + node.getGUID().toString(), message);
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

	static void generate() {
		// Object Model Diagrams
		IRPCollection allColl = irpPrj.getNestedElementsByMetaClass("ObjectModelDiagram", 1);

		for (int i = 1; i <= allColl.getCount(); i++) {
			IRPModelElement element = (IRPModelElement) allColl.getItem(i);
			sendNodeDataUpdate(element);
			sendNodeImageUpdate(element);
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		// Setup IBMRhapsody API
		irpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
		irpPrj = irpApp.activeProject();

		initClient();

		generate();
	}
}
