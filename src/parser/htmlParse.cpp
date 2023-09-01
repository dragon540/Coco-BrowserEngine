//
// Created by shobhit on 1/9/23.
//

#include "htmlParse.hpp"
#include "../lexer/htmlTokenise.hpp"
#include "../nTree/treeImplement.hpp"

void htmlParse::createAndSetPtr() {
    struct treeNode *tempTreeNode = DOM_tree.insertNode(DOM_tree.getCurrentNode());
    DOM_tree.setCurrentNode(tempTreeNode);
}
int htmlParse::checkIsCloseTagComplementary(std::string o_tag, std::string c_tag) {
    for(unsigned int idx = 1; idx < o_tag.length()-1; idx++) {
        if(o_tag[idx] != c_tag[idx+1])
            return 0;
    }
    return 1;
}

/*** REMOVE FOLLOWING COMMENTS ONCE FUNCTION IS FIXED***/
// this function is not working properly
// just leaving as it is to get blueprint for later
// decide about exact rendering detail
// returns root of the parsed html DOM
struct treeNode* htmlParse::htmlParser(std::string fPath) {
    htmlTokenise tokeniser;
    std::list<Token> htmlTokenTable = tokeniser.tokeniseHtml(fPath); // tokenising html tags
    std::list<Token> :: iterator it;
    it = htmlTokenTable.begin();
    while(it != htmlTokenTable.end()) {
        switch (it->tok_attribute) {
            case OPENING_TAG:
                // create node, set current node pointer to this new node
                createAndSetPtr();
                it++;
                break;
            case CLOSING_TAG:
                // set current tree node pointer to parent node and so on
                // check if closing node is corresponding close tag of current open node
                //if(checkIsCloseTagComplementary(it->tok_val, DOM_tree.getCurrentNode()->))
                break;
            case INNER_TEXT:
                // add data
                DOM_tree.addtxtContent(DOM_tree.getCurrentNode(), it->tok_val);
                it++;
                break;
        }
        it++;
    }
}
