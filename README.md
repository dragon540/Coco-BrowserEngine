# HTML Engine

Webpages are transferred over the internet in the form of HTML files. These files are rendered into webpages by a 
component of the web browsers called HTML engines.

This is an experimental HTML engine which aims to render a small subset of HTML. It passes the HTML input
file through a multiple steps involving in order to generate the rendered output.
1) Tokenizing the input HTML file.

2) Constructing a parse tree using the tokens obtained from first step.

3) Traversing the parsed tree in the correct order in order to render graphics.

## Build

Requires `Gtk-3.0` as a dependency.

    $ cd HtmlEngine
    $ cmake CMakeLists.txt

An executable will be generated at `cmake-build-debug` directory. 


