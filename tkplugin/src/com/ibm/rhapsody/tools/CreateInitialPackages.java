package com.ibm.rhapsody.tools;

import java.util.List;
import java.util.function.Consumer;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPClass;
import com.telelogic.rhapsody.core.IRPCollection;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPGraphElement;
import com.telelogic.rhapsody.core.IRPGraphNode;
import com.telelogic.rhapsody.core.IRPGraphicalProperty;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPPackage;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.RPGraphicalProperty;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

public class CreateInitialPackages {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IRPApplication app = RhapsodyAppServer.getActiveRhapsodyApplication();
		IRPProject prj = app.activeProject();
		
		IRPPackage vehiclePackage = prj.addPackage("Vehicles");
		IRPClass car = vehiclePackage.addClass("Car");
		IRPClass jeep = vehiclePackage.addClass("Jeep");
		IRPClass convertible = vehiclePackage.addClass("Convertible");
		jeep.addGeneralization(car);
		convertible.addGeneralization(car);
		IRPDiagram vehicleOmd = vehiclePackage.addObjectModelDiagram("vehicle_omd");
		IRPCollection vehicleClasses = vehiclePackage.getClasses();
		IRPCollection relationTypes = app.createNewCollection();
		relationTypes.setSize(1);
		relationTypes.setString(1, "Inheritance");
		vehicleOmd.populateDiagram(vehicleClasses, relationTypes, "fromto");
		
		IRPCollection els = vehicleOmd.getGraphicalElements();
		System.out.println(els.toList().toString());

        List<IRPGraphElement> diagramElements = els.toList();
        for (IRPGraphElement graphElement : diagramElements) {


            List<IRPGraphicalProperty> graphicalPropeties = null;

            try { /// in case the diagram graphic has no corresponding model element

            	System.out.print(graphElement.getModelObject().getDisplayName() + " ");
                System.out.println(graphElement.getModelObject().getMetaClass());
                System.out.println("==========");


                graphicalPropeties = graphElement.getAllGraphicalProperties().toList();

                for (IRPGraphicalProperty graphProp : graphicalPropeties) {

                    System.out.println(graphProp.getKey() + "\t" + graphProp.getValue());
                }
            }
            catch (Exception e) {	// diagram graphic has no corresponding model element.
                // graphic element may contain a "Type" graphical property
                System.out.println("<Unknown> Model Element");
                System.out.println("=======================");

                IRPCollection gps = graphElement.getAllGraphicalProperties();
                for (int i=0; i < gps.getCount(); i++) {
                    IRPGraphicalProperty gp = (IRPGraphicalProperty) gps.getItem(i);
                    if (gp != null) // Null graphical properties may exist
                        System.out.println(gp.getKey() + "\t" + gp.getValue());
                    }

                }
            System.out.println();
        }
        
        // Get image
        vehicleOmd.getPictureAs("C:\\Users\\thijs\\Desktop\\omd.jpg", "JPG", 0, null);
	}
}
