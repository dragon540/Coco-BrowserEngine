//
// Created by shobhit on 9/9/23.
//

#ifndef HTMLENGINE_RENDER_HPP
#define HTMLENGINE_RENDER_HPP

#include <string>

#include "parser/htmlParse.hpp"

#include <gtk-3.0/gtk/gtk.h>

// logic to render elements to the screen according to the nodes traversed is defined in activate()
static void activate(GtkApplication* gApp, gpointer user_data);

// renders the layout to the screen
int rendering(std::string fPath, int argc, char **argv);

#endif //HTMLENGINE_RENDER_HPP
