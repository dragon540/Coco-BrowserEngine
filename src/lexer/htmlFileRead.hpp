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

    // returns the index of the position of the string
    // where the open angular bracket is first found in the string
    int firstIdxOfOpenBrackInStr(std::string* combWord);

    // returns the index of the position of the string
    // where the close angular bracket is first found in the string
    int firstIdxOfCloseBrackInStr(std::string* word);

    bool isCloseComment(std::string* txt);
    bool isStartComment(std::string* txt);

    void removeComment(std::list<std::string>* wordList);
};


#endif //COCO_BROWSERENGINE_HTMLFILEREAD_HPP
