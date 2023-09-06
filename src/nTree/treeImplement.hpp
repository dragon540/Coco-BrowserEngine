//
// Created by shobhit on 26/8/23.
//

#ifndef HTMLENGINE_TREEIMPLEMENT_HPP
#define HTMLENGINE_TREEIMPLEMENT_HPP

#include <list>
#include <string>

// n-ary tree node
// operations to be performed :
// insertion - of new nodes at a particular node
// setting up data inside the node, when the pointer to the node is given
// reading - pre-order traversal
struct treeNode {
    struct treeNode* parentNode;
    std::list<struct treeNode*> childNode;

    // for unique identification of the type of node
    // important for knowing how to render the given data
    int tag_id;

    // defines tag attributes
    // example - <Body bgcolor="blue">
    std::string tagAttr = "";

    // for textual data to be displayed
    std::string txtContent = "";
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

    // assigns a tag id to the node pointed through the pointer in the function argument depending upon the tag
    void addTagID(struct treeNode* node, std::string tag);

    void addtxtContent(struct treeNode* node, std::string text);
    void addtagAttr(struct treeNode* node, std::string tagAttrStr);
};

#endif //HTMLENGINE_TREEIMPLEMENT_HPP
