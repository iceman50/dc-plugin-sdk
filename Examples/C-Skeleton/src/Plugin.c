/*
 * Copyright (C) 2012-2013 Jacek Sieka, arnetheduck on gmail point com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "stdafx.h"
#include "Plugin.h"

/* Include plugin SDK helpers from the pluginsdk directory. */
#include <dcapi/Config.h>

/* Variables */
DCCorePtr dcpp;

DCHooksPtr hooks;
DCLogPtr logging;

/* Hook subscription store - set this to the amount of hooks you require. */
#define HOOKS_SUBSCRIBED 0

const char* hookGuids[HOOKS_SUBSCRIBED] = {
	/* List hook identifiers here. Check pluginsdk/PluginDefs.h for available hooks. */
};

DCHOOK hookFuncs[HOOKS_SUBSCRIBED] = {
	/* List event handlers here (should be in sync with the hookGuids list). */
};

subsHandle subs[HOOKS_SUBSCRIBED];

/* Forward declarations */
Bool onLoad(DCCorePtr core, Bool install, Bool runtime);
Bool onUnload();

/* Plugin main function */
Bool DCAPI pluginMain(PluginState state, DCCorePtr core, dcptr_t pData) {
	switch(state) {
	case ON_INSTALL:
	case ON_LOAD:
	case ON_LOAD_RUNTIME:
		{
			return onLoad(core, state == ON_INSTALL, state == ON_INSTALL || state == ON_LOAD_RUNTIME);
		}

	case ON_UNINSTALL:
	case ON_UNLOAD:
		{
			return onUnload();
		}

	default:
		{
			return False;
		}
	}
}

Bool onLoad(DCCorePtr core, Bool install, Bool runtime) {
	/* Initialization phase. Initiate plugin SDK interfaces here. */

	uint32_t i = 0;

	dcpp = core;

	hooks = (DCHooksPtr)core->query_interface(DCINTF_HOOKS, DCINTF_HOOKS_VER);
	logging = (DCLogPtr)core->query_interface(DCINTF_LOGGING, DCINTF_LOGGING_VER);

	if(!init_cfg(core, PLUGIN_GUID) || !hooks || !logging) {
		return False;
	}

	if(install) {
		/* This only executes when the plugin has been installed for the first time. */
	}

	if(runtime) {
		/* If the plugin doesn't support being enabled at runtime, cancel its loading here. */
	}

	/* Register events. */
	while(i < HOOKS_SUBSCRIBED) {
		subs[i] = hooks->bind_hook(hookGuids[i], hookFuncs[i], NULL);
		++i;
	}

	/* Start the plugin logic here. */

	return True;
}

Bool onUnload() {
	uint32_t i = 0;
	while(i < HOOKS_SUBSCRIBED) {
		if(subs[i]) hooks->release_hook(subs[i]);
		++i;
	}

	uninit_cfg();

	return True;
}
