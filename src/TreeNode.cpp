//
// Created by Sherry Li on 2019/11/4.
//

#include "../include/TreeNode.h"
#include <string>
#include <utility>
using namespace std;

TreeNode::TreeNode(string label, int pos, int minusPos) {
    this->label = std::move(label);
    this->pos = pos;
    this->minusPos = minusPos;
}

string TreeNode::getLabel() {
    return this->label;
}

int TreeNode::getPos() {
    return this->pos;
}

int TreeNode::getMinusPos() {
    return this->minusPos;
}
