//
// Created by shobhit on 21/7/23.
//
#include <iostream>
#include <string>

#include "lexer/fileRead.hpp"
#include "lexer/htmlFileRead.hpp"
#include "lexer/htmlTokenise.hpp"

#include "nTree/treeImplement.hpp"

#include "parser/htmlParse.hpp"

int main() {
    /***htmlTokenise ht;
    std::list<Token> :: iterator it;
    std::list<Token> temp;
    temp = ht.tokeniseHtml("/home/shobhit/Desktop/HtmlEngine/example/tags.html");

    it = temp.begin();
    while(it != temp.end()) {
        std::cout << it->tok_val << " ---- " << it->tok_attribute << std::endl;
        it++;
    }***/

    /*****
    treeImplement ti;

    // printing root node
    std::cout << "root node - " << ti.getCurrentNode() << std::endl;
    struct treeNode *rt = ti.getCurrentNode();
    struct treeNode *l1t1, *l1t2, *l1t3;
    // 3 first level nodes created
    l1t1 = ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());
    l1t2 = ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());
    l1t3 = ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());

    // 2nd level nodes
    // 2 children of l1t1
    ti.setCurrentNode(l1t1);
    std::cout << "currently adding to l1t1 - " << ti.getCurrentNode() << std::endl;
    ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());
    ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());
    ti.gotoParent(ti.getCurrentNode()); // to goto root node

    std::cout << "check is it level 0 node - " << ti.getCurrentNode() << std::endl;

    ti.setCurrentNode(l1t2);
    std::cout << "currently adding to l1t1 - " << ti.getCurrentNode() << std::endl;
    ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());
    ti.insertNode(ti.getCurrentNode());
    std::cout << ti.getCurrentNode() << std::endl;
    ti.gotoParent(ti.getCurrentNode());

    std::cout << "check is it level 1 node 2 - " << ti.getCurrentNode() << std::endl;

    std::cout << "reading depth first" << std::endl;
    // not working properly
    ti.preordrTrav(rt);
     ****/

    htmlParse hp;
    struct treeNode* root;
    root = hp.htmlParser("/home/shobhit/Desktop/HtmlEngine/example/tags.html");
    std::list<treeNode*> :: iterator it;
    it = root->childNode.begin();
    root = *it;
    treeImplement ti;
    ti.preordrTrav(root);
    return 0;
}