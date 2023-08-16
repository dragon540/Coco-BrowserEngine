//
// Created by shobhit on 22/7/23.
//

#include "htmlFileRead.hpp"
#include "fileRead.hpp"

#include <iostream>

// takes a string pointer in argument
// and returns a substring(from position start_idx to end_idx) of the original string
std::string htmlFileRead::subStrOfStr(std::string* original_str, unsigned int start_idx, unsigned int end_idx) {
    std::string temp = "";
    for(unsigned int idx = start_idx; idx < end_idx; idx++) {
        temp += (*original_str)[idx];
    }
    return temp;
}

// returns the index of the position of the string
// where the open angular bracket is first found in the string
int htmlFileRead::firstIdxOfOpenBrackInStr(std::string* combWord) {
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

// returns the index of the position of the string
// where the close angular bracket is first found in the string
int htmlFileRead::firstIdxOfCloseBrackInStr(std::string* word) {
    int tag_idx = firstIdxOfOpenBrackInStr(word);
    if(tag_idx == -1)
        return -1;
    else {
        for(unsigned int idx = tag_idx + 1; idx < word->length(); idx++) {
            if((*word)[idx] == '>')
                return idx;
        }
    }
}

bool htmlFileRead::isCloseComment(std::string* txt) {
    if(txt->length() > 2) {
        unsigned int len = txt->length();
        if((*txt)[len - 1] == '>' && (*txt)[len - 2] == '-' && (*txt)[len - 3] == '-')
                return true;
        else
            return false;
    }
    else
        return false;
}

bool htmlFileRead::isStartComment(std::string* txt) {
    if(txt->length() > 3) {
        if( (*txt)[0] == '<' && (*txt)[1] == '!' && (*txt)[2] == '-' && (*txt)[3] == '-' ) {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void htmlFileRead::removeComment(std::list<std::string>* wordList) {
    std::list<std::string> :: iterator it;
    std::list<std::string> :: iterator temp_it;
    it = wordList->begin();
    while(it != wordList->end()) {
        std::string temp_str = *it;
        if(!isStartComment(&temp_str)) {
            it++;
        }
        else if(isStartComment(&temp_str)) {
            while(!isCloseComment(&temp_str)) {
                temp_it = it;
                it++;
                wordList->erase(temp_it);
                temp_str = *it;
            }
            temp_it = it;
            it++;
            wordList->erase(temp_it);
        }
    }
}

std::list<std::string> htmlFileRead::sepTagsAndWords(std::string filePath) {
    fileRead fr;
    std::list<std::string> wrd_list;
    std::list<std::string> :: iterator it;
    wrd_list = fr.readCombinedWord(filePath);
    it = wrd_list.begin();
    while(it != wrd_list.end()) {
        std::string curr_word = *it;
        int start_idx = firstIdxOfOpenBrackInStr(&curr_word);

        // if open angular bracket exist
        if(start_idx > -1) {
            std::string temp_wrd = subStrOfStr(&curr_word, 0, start_idx);
            if(start_idx != 0) // if open angular bracket exists at start of string then don't substring(0, strat_idx)
                               // as it will be empty string
                wrd_list.insert(it, temp_wrd);

            int end_idx = firstIdxOfCloseBrackInStr(&curr_word);
            if(end_idx > 0) {
                temp_wrd = subStrOfStr(&curr_word, start_idx, end_idx + 1);
                wrd_list.insert(it, temp_wrd);
                temp_wrd = subStrOfStr(&curr_word, end_idx + 1, curr_word.length());
                if(temp_wrd != "") {
                    wrd_list.insert(it, temp_wrd);
                }
                it = wrd_list.erase(it);
            }
            // if the substring to the right of close angular bracket is not empty
            if(firstIdxOfOpenBrackInStr(&temp_wrd) > -1)
                it--;
            else
                it++;
        }
        // if open angular bracket doesn't exist
        else
            it++;
    }
    removeComment(&wrd_list);
    //std::cout << wrd_list.size() << std::endl;
    return wrd_list;
}