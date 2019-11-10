//
// Created by Sherry Li on 2019/11/5.
//

#ifndef PREFIXTREEESPAN_PROJINST_H
#define PREFIXTREEESPAN_PROJINST_H

#include <vector>
#include <string>
#include "TreeNode.h"
#include "GrowElem.h"
#include "Tree.h"
#include "PreTree.h"
using namespace std;

//node in project instance
struct ProjInstNode {
    string label;   //label of the node (1, 2, ..., -1)
    int pos;        //position of the node in the origin tree
    int attachedTo; //number of node in prefix tree this node is attached to
};

class ProjInst {
private:
    vector<ProjInstNode> projInst;
    vector<ProjInstNode> prefix;
    int tranID;

public:
    ProjInst(int tranID);
    void setProjInst(vector<ProjInstNode> &projInst);
    vector<ProjInst> Project(Tree &tree, string &label);
    vector<GrowElem> getGEs();
    void setPrefix(vector<ProjInstNode> &nodes);
    static int getAttachedTo(Tree &tree, vector<ProjInstNode> &prefix, int pos);
    int getTranID();
};

#endif //PREFIXTREEESPAN_PROJINST_H
