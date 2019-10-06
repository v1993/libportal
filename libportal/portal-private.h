/*
 * Copyright (C) 2018, Matthias Clasen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "portal.h"

struct _XdpPortal {
  GObject parent_instance;

  GDBusConnection *bus;
  char *sender;

  /* inhibit */
  GHashTable *inhibit_handles;
  char *session_monitor_handle;
  guint state_changed_signal;

  /* spawn */
  guint spawn_exited_signal;

  /* updates */
  char *update_monitor_handle;
  guint update_available_signal;
  guint update_progress_signal;
};

#define PORTAL_BUS_NAME "org.freedesktop.portal.Desktop"
#define PORTAL_OBJECT_PATH  "/org/freedesktop/portal/desktop"
#define REQUEST_PATH_PREFIX "/org/freedesktop/portal/desktop/request/"
#define SESSION_PATH_PREFIX "/org/freedesktop/portal/desktop/session/"
#define REQUEST_INTERFACE "org.freedesktop.portal.Request"
#define SESSION_INTERFACE "org.freedesktop.portal.Session"

#define FLATPAK_PORTAL_BUS_NAME "org.freedesktop.portal.Flatpak"
#define FLATPAK_PORTAL_OBJECT_PATH "/org/freedesktop/portal/Flatpak"
#define FLATPAK_PORTAL_INTERFACE "org.freedesktop.portal.Flatpak"
