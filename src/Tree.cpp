//
// Created by Sherry Li on 2019/11/5.
//

#include "../include/Tree.h"
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;

struct RawNode{
    string label;
    int pos;
};

Tree::Tree(int tranID, string line) {
    this->tranID = tranID;

    vector<string> treeVector = split(line, ' ');
    stack<RawNode> inStack;

    for(int i = 0; i < treeVector.size(); ++i) {
        if (treeVector[i] != "-1") {
            RawNode rn = {treeVector[i], i};
            inStack.push(rn);

            //record unique label in this tree
            auto begin = this->uniqLabels.begin();
            auto end = this->uniqLabels.end();

            if (find(begin, end, treeVector[i]) != end)
                this->uniqLabels.push_back(treeVector[i]);

        } else {
            RawNode rn = inStack.top();
            inStack.pop();
            TreeNode tn = TreeNode(rn.label, rn.pos, i+1);
            this->tree.push_back(tn);
        }

        sort(this->tree.begin(), this->tree.end());
    }

}

vector<string> Tree::split(string &str, char delimiter) {
    vector<string> result;
    istringstream is(str);
    string label;

    while (getline(is, label, delimiter)) {
        result.push_back(label);
    }

    return result;
}

vector<string> Tree::getUniqLabels() {
    vector<string> result;
    for (TreeNode node: this->tree) {
        if (find(result.begin(), result.end(), node.getLabel()) != result.end()) {
            continue;
        } else {
            result.push_back(node.getLabel());
        }
    }
    return result;
}

int Tree::getTranID() {
    return this->tranID;
}

int Tree::getIdxByPos(int pos) {
    for (int i = 0; i < this->tree.size(); i++) {
        if (this->tree[i].getPos() == pos) {
            return i;
        } else {
            continue;
        }
    }
    return -1;
}

TreeNode Tree::getNodeByIdx(int idx) {
    return this->tree[idx];
}

vector<TreeNode> Tree::getTree() {
    return this->tree;
}