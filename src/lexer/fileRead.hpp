//
// Created by shobhit on 21/7/23.
//

#ifndef HTMLENGINE_FILEREAD_HPP
#define HTMLENGINE_FILEREAD_HPP

#include <string>
#include <list>

class fileRead {
private:
    std::list<std::string> readLine(std::string filePath);
public:
    std::list<std::string> readCombinedWord(std::string filePath);
};

#endif //HTMLENGINE_FILEREAD_HPP
