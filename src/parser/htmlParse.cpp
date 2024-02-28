//
// Created by shobhit on 1/9/23.
//

#include "htmlParse.hpp"
#include "../lexer/htmlTokenise.hpp"
#include "../nTree/treeImplement.hpp"

void htmlParse::createNodeAndSetPtr() {
    struct treeNode *tempTreeNode = DOM_tree.insertNode(DOM_tree.getCurrentNode());
    DOM_tree.setCurrentNode(tempTreeNode);
}

int htmlParse::isCloseTagComplementaryToOpenTag(std::string o_tag, std::string c_tag) {
    for(unsigned int idx = 1; idx < o_tag.length()-1; idx++) {
        if(o_tag[idx] != c_tag[idx+1])
            return 0;
    }
    return 1;
}

/*** TESTING OF THIS FUNCTION IS PENDING***/
// returns root of the parsed html DOM
struct treeNode* htmlParse::htmlParser(std::string fPath) {
    htmlTokenise tokeniser;
    std::list<Token> htmlTokenTable = tokeniser.tokeniseHtml(fPath); // tokenising html file
    std::list<Token> :: iterator it;
    it = htmlTokenTable.begin();
    while(it != htmlTokenTable.end()) {
        switch (it->tok_attribute) {
            case OPENING_TAG:
                // create node and set current node pointer to this new node
                createNodeAndSetPtr();

                // add tag id to the node
                DOM_tree.addTagID(DOM_tree.getCurrentNode(), it->tok_val);
                break;
            case CLOSING_TAG:
                // set current tree node pointer to parent node
                DOM_tree.setCurrentNode(DOM_tree.getCurrentNode()->parentNode);
                break;
            case INNER_TEXT:
                // add data
                DOM_tree.addtxtContent(DOM_tree.getCurrentNode(), it->tok_val);
                break;
        }
        // to read next token
        it++;
    }
    return (struct treeNode*)DOM_root;
}
