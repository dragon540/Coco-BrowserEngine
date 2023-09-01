//
// Created by shobhit on 26/8/23.
//

#include "treeImplement.hpp"

#include <stdlib.h>
#include <iostream>

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
    return currNode;
}
void treeImplement::setCurrentNode(struct treeNode *node) {
    currNode = node;
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

/*** REMOVE FOLLOWING COMMENTS ONCE FUNCTION IS FIXED***/
// this function is not working properly
// just leaving as it is to get blueprint for later
void treeImplement::depthFirstRead(struct  treeNode* root_ptr) {
    std::list<struct treeNode*> :: iterator it;
    it = root_ptr->childNode.begin();
    if((root_ptr->childNode).size() == 0) {
        std::cout << root_ptr << std::endl;
        std::cout << "leaf node" << std::endl;
    }
    else {
        while(it != root_ptr->childNode.end()) {
            depthFirstRead(*it);
            std::cout << root_ptr << std::endl;
            std::cout << "left node" << std::endl;
            it++;
        }
    }
}

void treeImplement::addtxtContent(treeNode *node, std::string text) {
    node->txtContent = text;
}
void treeImplement::addImgPath(treeNode *node, std::string path) {
    node->imgPath = path;
}
