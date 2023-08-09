//
// Created by shobhit on 22/7/23.
//

#ifndef COCO_BROWSERENGINE_HTMLFILEREAD_HPP
#define COCO_BROWSERENGINE_HTMLFILEREAD_HPP

#include <string>
#include <list>

class htmlFileRead {
public:
    std::list<std::string> sepTagsAndWords(std::string filePath);

private:
    // takes a string pointer in argument
    // and returns a substring(from position start_idx to end_idx) of the original string
    std::string subStrOfStr(std::string* original_str, unsigned int start_idx, unsigned int end_idx);

    int firstInstOfTagInStr(std::string* combWord);
};


#endif //COCO_BROWSERENGINE_HTMLFILEREAD_HPP
