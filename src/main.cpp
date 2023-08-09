//
// Created by shobhit on 21/7/23.
//
#include <iostream>
#include <string>

#include "lexer/fileRead.hpp"
#include "lexer/htmlFileRead.hpp"

int main() {
    std::cout << "Welcome to Coco browser engine" << std::endl;
    /***std::string x;

    htmlFileRead hfr;
    std::list<std::string> :: iterator it;
    std::list<std::string> temp;
    temp = hfr.sepTagsAndWords("/home/shobhit/Desktop/Coco-BrowserEngine/example/tags.html");

    it = temp.begin();
    while(it!=temp.end()) {
        std::cout << *it << std::endl;
        //std::cout << it->length() << std::endl;
        it++;
    }***/
    htmlFileRead hfr;
    std::string x = "Lang</u>";
    int c = hfr.firstInstOfTagInStr((&x));
    std::cout << c << std::endl;

    return 0;

}