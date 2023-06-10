package com.ibm.rhapsody.tools;

import org.eclipse.paho.client.mqttv3.IMqttMessageListener;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.IRPStatechart;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

public class PTMqttMessageListener implements IMqttMessageListener {

	@Override
	public void messageArrived(String topic, MqttMessage msg) throws Exception {
		
		IRPApplication rhpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
		IRPProject rhpProj = rhpApp.activeProject();
		IRPModelElement modelElement = rhpProj.findElementByGUID(msg.toString());
		
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
