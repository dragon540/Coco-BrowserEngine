//
// Created by shobhit on 26/8/23.
//

#ifndef COCO_BROWSERENGINE_TREEIMPLEMENT_HPP
#define COCO_BROWSERENGINE_TREEIMPLEMENT_HPP

#include <list>
#include <string>

// n-ary tree node
// operations to be performed :
// insertion - of new nodes at a particular node
// setting up data inside the node, when the pointer to the node is given
// reading - depth first reading
struct treeNode {
    struct treeNode* parentNode;
    std::list<struct treeNode*> childNode;
    //struct treeNode* childNode;
    std::string txtContent = "";
    std::string imgPath = ""; // path to image file when applicable
};

class treeImplement {
private:
    // current node pointer
    struct treeNode* currNode = NULL;
public:
    treeImplement(); // creates a root node
    struct treeNode* getCurrentNode();
    void setCurrentNode(struct treeNode* node);
    struct treeNode* insertNode(struct treeNode* pNode); // creates a child node for the pNode
    void gotoParent(struct treeNode* cNode); // sets current node to the parent node of the given node
    void depthFirstRead(struct  treeNode* root_ptr);
};

#endif //COCO_BROWSERENGINE_TREEIMPLEMENT_HPP
