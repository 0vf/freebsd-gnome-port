Index: src/backends/x11/meta-seat-x11.c
--- src/backends/x11/meta-seat-x11.c.orig
+++ src/backends/x11/meta-seat-x11.c
@@ -17,8 +17,9 @@
  * Author: Carlos Garnacho <carlosg@gnome.org>
  */
 #include "config.h"
-
+#ifdef __linux__
 #include <linux/input-event-codes.h>
+#endif
 #include <X11/extensions/XInput2.h>
 #include <X11/extensions/XKB.h>
 
@@ -1956,7 +1957,7 @@ get_source_device_checked (MetaSeatX11   *seat,
 
   return source_device;
 }
-
+#ifdef __linux__
 static uint32_t
 evdev_button_code (uint32_t x_button)
 {
@@ -1985,7 +1986,7 @@ evdev_button_code (uint32_t x_button)
 
   return button;
 }
-
+#endif
 gboolean
 meta_seat_x11_translate_event (MetaSeatX11  *seat,
                                XEvent       *xevent,
@@ -2272,7 +2273,9 @@ meta_seat_x11_translate_event (MetaSeatX11  *seat,
             event->button.time = xev->time;
             translate_coords (stage_x11, xev->event_x, xev->event_y, &event->button.x, &event->button.y);
             event->button.button = xev->detail;
+#ifdef __linux__
             event->button.evdev_code = evdev_button_code (xev->detail);
+#endif
             meta_input_device_x11_translate_state (event,
                                                    &xev->mods,
                                                    &xev->buttons,
