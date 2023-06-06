package com.ibm.rhapsody.tools;

import org.eclipse.paho.client.mqttv3.IMqttMessageListener;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

public class PTMqttMessageListener implements IMqttMessageListener {

	@Override
	public void messageArrived(String topic, MqttMessage msg) throws Exception {
		
		javax.swing.JOptionPane.showMessageDialog(null, "MQTT Message Received" + msg.toString() + " with topic" + topic, "ProteusExtractor", javax.swing.JOptionPane.PLAIN_MESSAGE);
		IRPApplication rhpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
		IRPProject rhpProj = rhpApp.activeProject();
		
		IRPModelElement modelElement = rhpProj.findElementByGUID(msg.toString());
		if (modelElement != null) {
			javax.swing.JOptionPane.showMessageDialog(null, "Opening diagram with metaclass" + modelElement.getMetaClass(), "ProteusExtractor", javax.swing.JOptionPane.PLAIN_MESSAGE);
			if (modelElement.getMetaClass().equals("ObjectModelDiagram")) {
				javax.swing.JOptionPane.showMessageDialog(null, "Opening diagram", "ProteusExtractor", javax.swing.JOptionPane.PLAIN_MESSAGE);
			}
		} else {
			javax.swing.JOptionPane.showMessageDialog(null, "Opening diagram but not found", "ProteusExtractor", javax.swing.JOptionPane.WARNING_MESSAGE);
			
		}
	}

}
