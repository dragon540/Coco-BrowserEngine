//
// Created by shobhit on 10/8/23.
//

#include "htmlTokenise.hpp"
#include "htmlFileRead.hpp"

int htmlTokenise::retTokNum(std::string* tok_val) {
    std::string tempStr = *tok_val;
    unsigned int len = tempStr.length();
    if(len < 3) {
        return INNER_TEXT;
    }
    else {
        if( (tempStr[0] == '<') && (tempStr[len-1] == '>') && (tempStr[1] != '/') ) {
            return OPENING_TAG;
        }
        else if( (tempStr[0] == '<') && (tempStr[len-1] == '>') && (tempStr[1] == '/') ) {
            return CLOSING_TAG;
        }
        else if( (tempStr[0] != '<') && (tempStr[len-1] != '>') ) {
            return INNER_TEXT;
        }
    }
}

std::list<Token> htmlTokenise::tokeniseHtml(std::string filePath) {
    htmlFileRead hfr;
    std::list<std::string> htmlWordList = hfr.sepTagsAndWords(filePath);
    std::list<Token> tok_table;
    std::list<std::string> :: iterator it;
    it = htmlWordList.begin();
    while(it != htmlWordList.end()) {
        Token temp;
        temp.tok_val = *it;
        temp.tok_attribute = retTokNum(&(*it));
        tok_table.push_back(temp);
        it++;
    }
    return tok_table;
}
