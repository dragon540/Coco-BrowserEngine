cmake_minimum_required(VERSION 3.24)
project(HtmlEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(HtmlEngine src/main.cpp src/lexer/fileRead.cpp src/lexer/fileRead.hpp src/lexer/htmlFileRead.cpp src/lexer/htmlFileRead.hpp src/lexer/htmlTokenise.cpp src/lexer/htmlTokenise.hpp src/nTree/treeImplement.cpp src/nTree/treeImplement.hpp src/parser/htmlParse.cpp src/parser/htmlParse.hpp src/render.cpp src/render.hpp)
target_link_libraries(HtmlEngine ${GTK3_LIBRARIES})