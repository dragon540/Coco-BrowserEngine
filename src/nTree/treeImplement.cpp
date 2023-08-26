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
struct treeNode* treeImplement::insertNode(struct treeNode *pNode) {
    struct treeNode* node = new struct treeNode;
    node->parentNode = pNode;
    //std::cout << pNode->childNode.size() << std::endl;
    pNode->childNode.push_back(node);
    return node;
}
