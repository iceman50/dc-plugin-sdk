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

/* Helpers around the DCConfig interface. */

#ifndef PLUGINSDK_CONFIG_H
#define PLUGINSDK_CONFIG_H

#include <dcapi/PluginDefs.h>

Bool DCAPI init_cfg(DCCorePtr core, const char* pluginGuid);
void DCAPI uninit_cfg();

char* DCAPI get_cfg(const char* name);
int32_t DCAPI get_cfg_int(const char* name);
int64_t DCAPI get_cfg_int64(const char* name);

void DCAPI set_cfg(const char* name, const char* value);
void DCAPI set_cfg_int(const char* name, int32_t value);
void DCAPI set_cfg_int64(const char* name, int64_t value);

ConfigValuePtr DCAPI get_core_cfg(const char* name);
void DCAPI free_core_cfg(ConfigValuePtr val);

char* DCAPI get_cfg_path(PathType path);
char* DCAPI get_install_path();

#endif
