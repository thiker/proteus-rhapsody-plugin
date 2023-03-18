package com.ibm.rhapsody.tools;

import com.telelogic.rhapsody.core.IRPDiagram;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPProject;
import com.telelogic.rhapsody.core.RPApplicationListener;

public class ApplicationListener extends RPApplicationListener {

	@Override
	public boolean afterAddElement(IRPModelElement pModelElement) {
		// TODO Auto-generated method stub
		System.out.println("added element");
		return false;
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
		return "proteus-application-listener";
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


}
