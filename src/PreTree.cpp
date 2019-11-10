//
// Created by Sherry Li on 2019/11/4.
//

#include "../include/PreTree.h"
//#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
using namespace std;

//TODO: implement toString()
string PreTree::toString() {
    string result;

    return result;
}

PreTree::PreTree(const string& label) {
    PreTreeNode node = {label, 0};
    this->prefixTree.push_back(node);
}

PreTree* PreTree::grow(GrowElem &GE) {
    PreTreeNode node = {GE.getLabel(), GE.getAttached()};
    this->prefixTree.push_back(node);
    return this;
}

vector<PreTreeNode> PreTree::getPreTree() {
    return this->prefixTree;
}

PreTree::PreTree() = default;
