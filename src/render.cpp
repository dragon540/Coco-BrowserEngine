//
// Created by shobhit on 9/9/23.
//

#include "render.hpp"
#include "parser/htmlParse.hpp"
#include "nTree/treeImplement.hpp"

#include <gtk-3.0/gtk/gtk.h>
#include <iostream>

static void activate(GtkApplication *gApp, gpointer user_data) {
    GtkWidget *win;
    win = gtk_application_window_new(gApp);
    gtk_window_set_resizable (GTK_WINDOW(win), TRUE);
    gtk_window_set_default_size (GTK_WINDOW(win), 1560, 1560);

    // traverse the tree
    // and render the required elements to the screen

    gtk_widget_show_all(win);
}

int rendering(std::string fPath, int argc, char **argv) {
    GtkApplication *app;
    app = gtk_application_new("html.engine.render", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int ret = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return ret;
}