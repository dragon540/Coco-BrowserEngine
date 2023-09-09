//
// Created by shobhit on 9/9/23.
//

#include "render.hpp"

#include <gtk-3.0/gtk/gtk.h>

// logic to render elements to the screen according to the nodes traversed is defined in activate()
static void activate(GtkApplication* x, gpointer user_data) {

}
// renders the layout to the screen
int render(std::string fPath, int argc, char **argv) {
    GtkApplication *app;
    app = gtk_application_new("practice.shobhit", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int ret = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return ret;
}