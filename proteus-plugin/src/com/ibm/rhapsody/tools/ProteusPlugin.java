package com.ibm.rhapsody.tools;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPPackage;
import com.telelogic.rhapsody.core.IRPUseCase;
import com.telelogic.rhapsody.core.RPUserPlugin;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

public class ProteusPlugin extends RPUserPlugin{

	@Override
	public void RhpPluginInit(IRPApplication rpyApplication) {
		ProteusExtractor.getInstance().refresh();
	}

	@Override
	public void RhpPluginInvokeItem() {
		// TODO Auto-generated method stub
	}

	@Override
	public void OnMenuItemSelect(String menuItem) {
		 System.out.println(menuItem);
		ProteusExtractor.getInstance().refresh();
	}

	@Override
	public void OnTrigger(String trigger) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean RhpPluginCleanup() {
		return false;
	}

	@Override
	public void RhpPluginFinalCleanup() {
		ProteusExtractor.getInstance().dispose();
	}

}
