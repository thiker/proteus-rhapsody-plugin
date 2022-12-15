package com.ibm.rhapsody.tools;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.List;
import java.util.function.Consumer;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPClass;
import com.telelogic.rhapsody.core.IRPCollection;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPGraphElement;
import com.telelogic.rhapsody.core.IRPGraphNode;
import com.telelogic.rhapsody.core.IRPGraphicalProperty;
import com.telelogic.rhapsody.core.IRPImageMap;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPObjectModelDiagram;
import com.telelogic.rhapsody.core.IRPPackage;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.RPGraphicalProperty;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

public class Test {

	static void saveOmd(IRPDiagram omd, IRPApplication app) {
		String omdName = omd.getDisplayName().toString();
		System.out.println("Saving " + omdName);
		IRPCollection imageMaps = app.createNewCollection();
	    omd.getPictureAs(System.getProperty("user.dir").toString() + "/output/"+ omdName + ".jpeg", "JPEG", 1, imageMaps);
	    
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
	}
	
	public static void main(String[] args) {
		IRPApplication app = RhapsodyAppServer.getActiveRhapsodyApplication();
		IRPProject prj = app.activeProject();
		IRPPackage pckg = (IRPPackage)prj.findNestedElement("SystemContextPkg", "Package");
		IRPCollection omds = (IRPCollection)pckg.getObjectModelDiagrams();
		IRPDiagram omd = (IRPDiagram)omds.toList().get(0);
		saveOmd(omd,app);
	}
}
