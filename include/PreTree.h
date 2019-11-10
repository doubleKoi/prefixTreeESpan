//
// Created by Sherry Li on 2019/11/4.
//

#ifndef PREFIXTREEESPAN_PRETREE_H
#define PREFIXTREEESPAN_PRETREE_H

#include <vector>
#include <string>
#include "GrowElem.h"

using namespace std;

struct PreTreeNode{
    string label;
    int parent;
};

class PreTree {
private:
    vector<PreTreeNode> prefixTree;      //subtree pattern

public:
    PreTree();
    PreTree(const string& label);
    PreTree * grow(GrowElem &GE);
    string toString();
    vector<PreTreeNode> getPreTree();
};


#endif //PREFIXTREEESPAN_PRETREE_H
