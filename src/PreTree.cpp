//
// Created by Sherry Li on 2019/11/4.
//

#include "../include/PreTree.h"
//#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
using namespace std;

string PreTree::toString() {
    if (this->prefixTree.empty()) {
        return "";
    } else {
        string result = this->prefixTree[0].label + " ";
        result = incrStr(result, this->prefixTree, 1);
        result += "-1 ";
        return result;
    }
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

string PreTree::incrStr(string str, vector<PreTreeNode> &nodes, int attached) {
    for (int i = attached; i < nodes.size(); i++) {
        if (nodes[i].parent == attached) {
            str += (nodes[i].label + " ");
            incrStr(str, nodes, i+1);
            str += "-1 ";
        }
    }
    return str;
}

PreTree::PreTree() = default;
