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
            RawNode rn = {treeVector[i], i+1};
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
    return this->uniqLabels;
}

vector<ProjInst> Tree::Project(const string& label) {
    vector<ProjInst> instances;

    for (int i = 0; i < this->tree.size(); i++) {
        TreeNode node = this->tree[i];
        string lb = node.getLabel();
        if (lb == label) {
            vector<ProjInstNode> nodes;
            ProjInst instance = ProjInst(this->tranID);

            for (int j = i+1; j < tree.size(); j++) {
                TreeNode nd = this->tree[j];
                if (nd.getPos() < node.getMinusPos()) {
                    ProjInstNode node = {nd.getLabel(), nd.getPos(), 1};
                    nodes.push_back(node);
                } else {
                    break;
                }
            }
            instance.setProjInst(nodes);
            instances.push_back(instance);
        }
    }
    return instances;
}
