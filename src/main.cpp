//
// Created by shobhit on 21/7/23.
//
#include <iostream>
#include <string>

#include "lexer/fileRead.hpp"

int main() {
    std::cout << "Welcome to Coco browser engine" << std::endl;
    std::string x;

    fileRead fr;
    std::list<std::string> :: iterator it;
    std::list<std::string> temp;
    temp = fr.readCombinedWord("/home/shobhit/Desktop/Coco-BrowserEngine/example/tags.html");

    it = temp.begin();
    while(it!=temp.end()) {
        std::cout << *it << std::endl;
        //std::cout << it->length() << std::endl;
        it++;
    }

}