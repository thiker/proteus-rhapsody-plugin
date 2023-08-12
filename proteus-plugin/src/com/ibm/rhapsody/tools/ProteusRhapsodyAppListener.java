package com.ibm.rhapsody.tools;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.RPApplicationListener;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

/**
 * App listener for Rhapsody that is used by the ProteusPlugin to be notified when model elements change.
 * @author thijskoenraadt
 *
 */
public class ProteusRhapsodyAppListener extends RPApplicationListener{

	@Override
	public boolean afterAddElement(IRPModelElement pModelElement) {
		return false; // or return true.
	}

	@Override
	public boolean afterProjectClose(String bstrProjectName) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean beforeProjectClose(IRPProject pProject) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String getId() {
		return "ProteusAppListener";
	}

	@Override
	public boolean onDiagramOpen(IRPDiagram pDiagram) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean onDoubleClick(IRPModelElement pModelElement) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean onFeaturesOpen(IRPModelElement pModelElement) {
		// TODO Auto-generated method stub
		return false;
	}
	
	@Override
	public boolean onElementsChanged(String GUIDs) {
		// When no elements have changed
		if (GUIDs.trim().length() == 0) {
			return true;
		}
		
		// Get a reference to the current project.
		IRPApplication rhpApp = RhapsodyAppServer.getActiveRhapsodyApplication();
		IRPProject rhpProj = rhpApp.activeProject();
		
		// Get the GUIDS of the elements that have changed.
		String[] GUIDsArray = GUIDs.split(",");
		
		// Extract all elements and send the updates to Proteus in Unity.
		for (int i = 0;  i < GUIDsArray.length; i++)
		{
			IRPModelElement currElement = rhpProj.findElementByGUID(GUIDsArray[i].trim());
			ProteusExtractor.getInstance().extractModelElement(currElement);
		}
		return true;
	}

}
