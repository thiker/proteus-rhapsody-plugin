package com.ibm.rhapsody.tools;

import com.telelogic.rhapsody.core.IRPApplication;

public class pluginApplicationListener {
	public static void RhpPluginInit(IRPApplication rpApp) {
		ApplicationListener app = new ApplicationListener();
		app.connect(rpApp);
	}
}
