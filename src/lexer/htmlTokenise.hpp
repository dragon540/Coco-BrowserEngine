//
// Created by shobhit on 10/8/23.
//

#ifndef COCO_BROWSERENGINE_HTMLTOKENISE_HPP
#define COCO_BROWSERENGINE_HTMLTOKENISE_HPP

#include <string>
#include <list>

#define OPENING_TAG 7
#define CLOSING_TAG 8
#define INNER_TEXT 9

struct Token {
public:
    std::string tok_val;
    int tok_attribute;
};
class htmlTokenise {
public:
    std::list<Token> tokeniseHtml(std::string filePath);

    int retTokNum(std::string* tok_val);
};

#endif //COCO_BROWSERENGINE_HTMLTOKENISE_HPP
