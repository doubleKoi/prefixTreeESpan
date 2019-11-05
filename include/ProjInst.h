//
// Created by Sherry Li on 2019/11/5.
//

#ifndef PREFIXTREEESPAN_PROJINST_H
#define PREFIXTREEESPAN_PROJINST_H

#include <vector>
#include <string>
#include "TreeNode.h"
using namespace std;

//node in project instance
struct ProjInstNode {
    string label;   //label of the node (1, 2, ..., -1)
    int pos;        //position of the node in the origin tree
};

class ProjInst {
private:
    vector<ProjInstNode> projInst;
    int tranID;

public:
    ProjInst();
    void setProjInst(vector<ProjInstNode> projInst);
    void setTranID(int tranID);
    ProjInst Project(string label);
};

#endif //PREFIXTREEESPAN_PROJINST_H
