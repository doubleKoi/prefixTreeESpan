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
    vector<string> uniqLabels;

public:
    Tree(int tranID, string line);
    static vector<string> split(string& str, char delimiter);
    vector<string> getUniqLabels();
    //vector<ProjInst> Project(const string& label);
    int getTranID();
    int getIdxByPos(int pos);
    TreeNode getNodeByIdx(int idx);
    vector<TreeNode> getTree();
};


#endif //PREFIXTREEESPAN_TREE_H
