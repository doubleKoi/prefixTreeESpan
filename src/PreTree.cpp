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
    for(string label: this->prefixTree) {
        result += (label + " ");
    }
    return result;
}

PreTree::PreTree(const string& label) {
    this->prefixTree.push_back(label);
}

PreTree* PreTree::grow(GrowElem &GE) {
    this->prefixTree.push_back(GE.getLabel());
    return this;
}
