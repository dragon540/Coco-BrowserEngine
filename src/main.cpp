//
// Created by shobhit on 21/7/23.
//
#include <iostream>
#include <string>

int main() {
    std::cout << "Welcome to Coco browser engine" << std::endl;
    std::string x;
    do {
        std::cout << ">>" << std::endl;
        std::cin >> x;
    }
    while(x != "exit");
}