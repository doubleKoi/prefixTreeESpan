//
// Created by Sherry Li on 2019/11/4.
//

#include "../include/PreTree.h"
#include <string>
using namespace std;

//TODO: implement toString()
string PreTree::toString() {
    return "";
}

PreTree::PreTree() {
    vector<string> prefTree;
    this->prefixTree = prefTree;
}

PreTree PreTree::grow(GrowElem &GE) {
    return PreTree();
}
