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

#ifndef PLUGIN_STDAFX_H
#define PLUGIN_STDAFX_H

#ifdef _WIN32

#include <windows.h>
#include <tchar.h>

#else

#include <unistd.h>

#endif

#include <dcapi/PluginDefs.h>

#include "version.h"

#define PLUGIN_VERSION (PLUGIN_VERSION_MAJOR + (PLUGIN_VERSION_MINOR >= 10 ? PLUGIN_VERSION_MINOR >= 100 ? \
	PLUGIN_VERSION_MINOR / 1000. : PLUGIN_VERSION_MINOR / 100. : PLUGIN_VERSION_MINOR / 10.))

#endif
