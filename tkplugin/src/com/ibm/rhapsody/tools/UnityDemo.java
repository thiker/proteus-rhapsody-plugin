package com.ibm.rhapsody.tools;

import java.nio.file.Files;
import java.io.File;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.List;
import java.util.function.Consumer;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

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

public class UnityDemo {

	static byte[] saveOmd(IRPDiagram omd, IRPApplication app) throws IOException {
		String omdName = omd.getDisplayName().toString();
		System.out.println("Saving " + omdName);
		IRPCollection imageMaps = app.createNewCollection();
		String filePath = System.getProperty("user.dir").toString() + "/output/"+ omdName + ".jpeg";
	    omd.getPictureAs(filePath, "JPEG", 1, imageMaps);
	    File fi = new File(filePath);
	    byte[] fileContent = Files.readAllBytes(fi.toPath());
	    
	    try (PrintStream out = new PrintStream(new FileOutputStream(System.getProperty("user.dir").toString() + "/output/"+omdName + ".html"))) {
	    	
	    	
	    	out.println("<!DOCTYPE html>\r\n"
	    			+ "<html>\r\n"
	    			+ "\r\n"
	    			+ "<body>\r\n"
	    			+ "    <img src=\" "+ omdName + ".jpeg\" usemap=\"#map\">");
	    
		    out.println("<map name=\"map\">");
		    for(IRPImageMap map : (List<IRPImageMap>)imageMaps.toList()) {
		    	out.print("<area coords=\"");
		    	out.print(map.getPoints().toString());
		    	out.print("\" shape=\"");
		    	out.print("poly");
		    	out.print("\" href=\"");
		    	out.print(map.getName().replace(' ', '-') + ".html");
		    	out.print("\">\n");
		    }
		    out.println("</map>");
		    
		    out.println("</body>\r\n"
		    		+ "\r\n"
		    		+ "</html>");
	    } catch(Exception e) {}
	    
	    return fileContent;
	}
	
	public static void main(String[] args) throws IOException, InterruptedException {
		 String topic        = "M2MQTT_Unity/test";
        String content      = "Message from MqttPublishSample";
        int qos             = 2;
        String broker       = "tcp://localhost:1883";
        String clientId     = "JavaSample";
        MemoryPersistence persistence = new MemoryPersistence();

        try {
   		    MqttClient sampleClient = new MqttClient(broker, clientId, persistence);
            MqttConnectOptions connOpts = new MqttConnectOptions();
            connOpts.setCleanSession(true);
            System.out.println("Connecting to broker: "+broker);
            sampleClient.connect(connOpts);
            System.out.println("Connected");
            
            // Get image
    		IRPApplication app = RhapsodyAppServer.getActiveRhapsodyApplication();
    		IRPProject prj = app.activeProject();
    		IRPPackage pckg = (IRPPackage)prj.findNestedElement("Testing", "Package");
    		IRPCollection omds = (IRPCollection)pckg.getObjectModelDiagrams();
    		IRPDiagram omd = (IRPDiagram)omds.toList().get(0);
    		
    		while(true) {
        		byte[] pictureBytes = saveOmd(omd,app);
        		
                System.out.println("Publishing message: "+content);
                MqttMessage message = new MqttMessage(pictureBytes);
                message.setQos(qos);
                sampleClient.publish(topic, message);
                System.out.println("Message published");
    			Thread.sleep(1);
    		}

            
        } catch(MqttException me) {
            System.out.println("reason "+me.getReasonCode());
            System.out.println("msg "+me.getMessage());
            System.out.println("loc "+me.getLocalizedMessage());
            System.out.println("cause "+me.getCause());
            System.out.println("excep "+me);
            me.printStackTrace();
        }
	}
}
