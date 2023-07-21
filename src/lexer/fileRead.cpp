//
// Created by shobhit on 21/7/23.
//

#include "fileRead.hpp"

#include <fstream>

std::list<std::string> fileRead::readLine(std::string filePath) {
    std::ifstream file;
    file.open(filePath);
    std::list<std::string> lineTable;

    if(file.is_open()) {
        while(file) {
            std::string t_line = "";
            std::getline(file, t_line);
            lineTable.push_back(t_line);
        }
    }
    file.close();
    return lineTable;
}

std::list<std::string> fileRead::readTempWord(std::string filePath) {
    std::list<std::string> temp = readLine(filePath);
    std::list<std::string> tempWords;
    std::list<std::string> :: iterator it;
    it = temp.begin();
    while(it != temp.end()) {
        std::string t_line = *it;
        std::string t_word = "";
        for(unsigned int idx = 0; idx <= t_line.length(); idx++) {
            if(t_line[idx] == ' ') {
                tempWords.push_back(t_word);
                t_word = "";
            }
            t_word += t_line[idx];
            if(idx == t_line.length()-1) {
                tempWords.push_back(t_word);
            }
        }
        it++;
    }
    return tempWords;
}