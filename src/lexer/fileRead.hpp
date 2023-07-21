//
// Created by shobhit on 21/7/23.
//

#ifndef COCO_BROWSERENGINE_FILEREAD_HPP
#define COCO_BROWSERENGINE_FILEREAD_HPP

#include <string>
#include <list>

class fileRead {
public:
//private:
    std::list<std::string> readLine(std::string filePath);
    std::list<std::string> readTempWord(std::string filePath);
    std::list<std::string> readCombinedWord(std::string filePath);
    std::list<std::string> readSepWord(std::string filePath);
public:
    std::list<std::string> readWord(std::string filePath);
};

#endif //COCO_BROWSERENGINE_FILEREAD_HPP
