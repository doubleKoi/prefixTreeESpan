//
// Created by Sherry Li on 2019/11/4.
//

#ifndef PREFIXTREEESPAN_PRETREE_H
#define PREFIXTREEESPAN_PRETREE_H

#include <vector>
#include <string>
#include "GrowElem.h"

using namespace std;

class PreTree {
private:
    vector<string> prefixTree;      //subtree pattern

public:
    PreTree(const string& label);
    PreTree * grow(GrowElem &GE);
    string toString();
};


#endif //PREFIXTREEESPAN_PRETREE_H
