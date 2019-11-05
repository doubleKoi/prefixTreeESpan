//
// Created by Sherry Li on 2019/11/5.
//

#ifndef PREFIXTREEESPAN_TREE_H
#define PREFIXTREEESPAN_TREE_H

#include <vector>
#include "TreeNode.h"
using namespace std;

class Tree {
private:
    int tranID;
    vector<TreeNode> tree;

public:
    Tree(int tranID, string line);
    static vector<string> split(string& str, char delimiter);
};


#endif //PREFIXTREEESPAN_TREE_H
