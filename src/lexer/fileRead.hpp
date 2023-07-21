//
// Created by shobhit on 21/7/23.
//

#ifndef COCO_BROWSERENGINE_FILEREAD_HPP
#define COCO_BROWSERENGINE_FILEREAD_HPP

#include <string>
#include <list>

class fileRead {
private:
    std::list<std::string> readLine(std::string filePath);
public:
    std::list<std::string> readCombinedWord(std::string filePath);
};

#endif //COCO_BROWSERENGINE_FILEREAD_HPP
