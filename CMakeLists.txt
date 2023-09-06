cmake_minimum_required(VERSION 3.24)
project(HtmlEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(HtmlEngine src/main.cpp src/lexer/fileRead.cpp src/lexer/fileRead.hpp src/lexer/htmlFileRead.cpp src/lexer/htmlFileRead.hpp src/lexer/htmlTokenise.cpp src/lexer/htmlTokenise.hpp src/nTree/treeImplement.cpp src/nTree/treeImplement.hpp src/parser/htmlParse.cpp src/parser/htmlParse.hpp)