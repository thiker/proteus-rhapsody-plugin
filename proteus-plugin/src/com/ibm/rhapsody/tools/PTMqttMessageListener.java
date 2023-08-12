package com.ibm.rhapsody.tools;

import org.eclipse.paho.client.mqttv3.IMqttMessageListener;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.IRPStatechart;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

/**
 * MQTT Message listener used by the Proteus plugin to receive incoming data from Proteus in Unity.
 *
 */
public class PTMqttMessageListener implements IMqttMessageListener {

	@Override
	public void messageArrived(String topic, MqttMessage msg) throws Exception {
		// Get a reference to the active project.
		IRPApplication rhpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
		IRPProject rhpProj = rhpApp.activeProject();
		
		// Find the model element that the message is targeted to.
		IRPModelElement modelElement = rhpProj.findElementByGUID(msg.toString());
		
		// Opens the diagram in IBM-Rhapsody.
		if (modelElement != null) {
			//modelElement.openFeaturesDialog(1);
			if (modelElement.getMetaClass().equals("ObjectModelDiagram")) {
				((IRPDiagram)modelElement).openDiagram();
			} else if (modelElement.getMetaClass().equals("Statechart")) {
				((IRPStatechart)modelElement).getStatechartDiagram().openDiagram();
				
			}
		}
	}

}
