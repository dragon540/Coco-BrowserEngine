cmake_minimum_required(VERSION 3.24)
project(Coco-BrowserEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coco-BrowserEngine src/main.cpp src/lexer/fileRead.cpp src/lexer/fileRead.hpp src/lexer/htmlFileRead.cpp src/lexer/htmlFileRead.hpp src/lexer/htmlTokenise.cpp src/lexer/htmlTokenise.hpp src/nTree/treeImplement.cpp src/nTree/treeImplement.hpp src/parser/htmlParse.cpp src/parser/htmlParse.hpp)