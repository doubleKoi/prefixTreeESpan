//
// Created by Sherry Li on 2019/11/4.
//

#ifndef PREFIXTREEESPAN_TREENODE_H
#define PREFIXTREEESPAN_TREENODE_H

#include <string>
using namespace std;

class TreeNode {
private:
     string label;      //label for the tree node
     int    pos;        //position of the node itself
     int    minusPos;   //position of the corresponding minus notation

public:
    TreeNode(string label, int pos, int minusPos);
    string getLabel();
    int getPos();
    int getMinusPos();
};

#endif //PREFIXTREEESPAN_TREENODE_H
