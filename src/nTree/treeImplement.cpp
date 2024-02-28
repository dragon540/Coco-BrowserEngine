//
// Created by shobhit on 26/8/23.
//

#include "treeImplement.hpp"

#include <stdlib.h>
#include <iostream>

#include "../defs.hpp"

// class constructor
// creates a root node for the tree
// and sets the current node pointer to the root node
treeImplement::treeImplement() {
    //struct treeNode* temp = (struct treeNode*) malloc(sizeof(struct treeNode));
    struct treeNode* temp = new struct treeNode;
    temp->parentNode = NULL;
    setCurrentNode(temp);
}
struct treeNode* treeImplement::getCurrentNode() {
    return currentNode;
}
void treeImplement::setCurrentNode(struct treeNode *node) {
    currentNode = node;
}

// creates a child node for the pNode
// then sets the current node to this newly created node
struct treeNode* treeImplement::insertNode(struct treeNode *pNode) {
    struct treeNode* node = new struct treeNode;
    node->parentNode = pNode;
    //std::cout << pNode->childNode.size() << std::endl;
    pNode->childNode.push_back(node);
    setCurrentNode(node);
    return node;
}

// sets current node to the parent node of the given node
void treeImplement::gotoParent(struct treeNode* cNode) {
    if(cNode->parentNode == NULL)
        setCurrentNode(cNode);
    else
        setCurrentNode(cNode->parentNode);
}

int tab = 0;
void treeImplement::preorderTraversal(struct  treeNode* root_ptr) {
    std::cout << std::endl;
    for(int i = 0;i<tab;i++) {
        std::cout << '\t';
    }
    std::cout << "( ";
    tab++;
    //std::cout << root_ptr->tag_id << std::endl;
    std::cout << root_ptr->tag_id << " ";
    //std::cout << root_ptr->data << std::endl;
    std::cout << root_ptr->data << " ";
    std::cout << " -> ";
    std::list<treeNode*> :: iterator it;
    it = root_ptr->childNode.begin();
    while(it != root_ptr->childNode.end()) {
        preorderTraversal(*it);
        std::cout << " )";
        tab--;
        it++;
    }
}
void treeImplement::addTagID(struct treeNode* node, std::string tag) {
    if(tag == "<Html>") node->tag_id = HTML_TAG;
    else if(tag == "<Head>") node->tag_id = HEAD_TAG;
    else if(tag == "<title>") node->tag_id = TITLE_TAG;
    else if(tag == "<Body>") node->tag_id = BODY_TAG;
    else if(tag == "<p>") node->tag_id = PARAGRAPH_TAG;
    else if(tag == "<h1>") node->tag_id = HEADING1_TAG;
    else if(tag == "<h2>") node->tag_id = HEADING2_TAG;
    else if(tag == "<h3>") node->tag_id = HEADING3_TAG;
    else if(tag == "<h4>") node->tag_id = HEADING4_TAG;
    else if(tag == "<h5>") node->tag_id = HEADING5_TAG;
    else if(tag == "<h6>") node->tag_id = HEADING6_TAG;
    else if(tag == "<b>") node->tag_id = BOLD_TAG;
    else if(tag == "<i>") node->tag_id = ITALICS_TAG;
    else if(tag == "<u>") node->tag_id = UNDERLINE_TAG;
    // add more
}

void treeImplement::addtxtContent(struct treeNode *node, std::string text) {
    node->data += text;
}
void treeImplement::addtagAttr(struct treeNode* node, std::string tagAttrStr) {
    node->tagAttr = tagAttrStr;
}