package com.ibm.rhapsody.tools;

import com.telelogic.rhapsody.core.IRPApplication;
import com.telelogic.rhapsody.core.IRPModelElement;
import com.telelogic.rhapsody.core.IRPPackage;
import com.telelogic.rhapsody.core.IRPUseCase;
import com.telelogic.rhapsody.core.RPUserPlugin;
import com.telelogic.rhapsody.core.RhapsodyAppServer;

/**
 * Proteus plugin that handles the extraction of 2D system models from IBM-Rhapsody and converts them to 3DMl formatted data that can be send to Proteus in Unity.
 * @author thijskoenraadt
 *
 */
public class ProteusPlugin extends RPUserPlugin{

	@Override
	public void RhpPluginInit(IRPApplication rpyApplication) {
		// Remove the next line if you would like to automatically start Proteus on load.
		//ProteusExtractor.getInstance().refresh();
	}

	@Override
	public void RhpPluginInvokeItem() {
		// TODO Auto-generated method stub
	}

	@Override
	public void OnMenuItemSelect(String menuItem) {
		// Link the GUI's RefreshProteus button
		if (menuItem.equals("RefreshProteus")) {
			ProteusExtractor.getInstance().refresh();		
		}
		
		// Link the GUI'ds OpenInProteus button
		if (menuItem.equals("OpenInProteus")) {
			ProteusExtractor.getInstance().OpenDiagramOfSelectedElement();
		}
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
		// Dispose the extractor when the plugin is unloaded.
		ProteusExtractor.getInstance().dispose();
	}

}
