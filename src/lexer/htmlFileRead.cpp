//
// Created by shobhit on 22/7/23.
//

#include "htmlFileRead.hpp"
#include "fileRead.hpp"


// takes a string pointer in argument
// and returns a substring(from position start_idx to end_idx) of the original string
std::string htmlFileRead::subStrOfStr(std::string* original_str, unsigned int start_idx, unsigned int end_idx) {
    std::string temp = "";
    for(unsigned int idx = start_idx; idx < end_idx; idx++) {
        temp += (*original_str)[idx];
    }
    return temp;
}

int htmlFileRead::firstInstOfTagInStr(std::string* combWord) {
    int startTagIdx = -1;
    int conf_startTagIdx = -1;
    for(unsigned int idx = 0; idx < combWord->length(); idx++) {
        if((*combWord)[idx] == '<') {
            startTagIdx = idx;
            break;
        }
    }
    if(startTagIdx >= 0) {
        for(unsigned int idx = startTagIdx + 1; idx < combWord->length(); idx++) {
            if((*combWord)[idx] == '<') {
                break;
            }
            else if((*combWord)[idx] == '>') {
                conf_startTagIdx = startTagIdx;
                break;
            }
        }
    }
    return conf_startTagIdx;
}

std::list<std::string> htmlFileRead::sepTagsAndWords(std::string filePath) {
    fileRead fr;
    std::list<std::string> comb_wrd;
    std::list<std::string> :: iterator it;
    comb_wrd = fr.readCombinedWord(filePath);
    it = comb_wrd.begin();

    while(it != comb_wrd.end()) {
        std::string temp = *it;
        std::string new_wrd = "";
        int tag_idx = firstInstOfTagInStr(&temp);
        if(tag_idx > -1) {
            std::string temp_wrd = subStrOfStr(&temp, 0, tag_idx);
            comb_wrd.insert(it, temp_wrd);
            temp_wrd = subStrOfStr(&temp, tag_idx, temp.length());
            comb_wrd.insert(it, temp_wrd);
            it = comb_wrd.erase(it);
        }
        it++;
    }
    return comb_wrd;
}