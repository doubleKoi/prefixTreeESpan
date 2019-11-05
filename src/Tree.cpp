//
// Created by Sherry Li on 2019/11/5.
//

#include "../include/Tree.h"
#include <sstream>
#include <stack>
using namespace std;

struct RawNode{
    string label;
    int pos;
};

//TODO: construct tree from file line
Tree::Tree(int tranID, string line) {
    this->tranID = tranID;

    vector<string> treeVector = split(line, ' ');
    stack<RawNode> inStack;

    for(int i = 0; i < treeVector.size(); ++i) {
        if (treeVector[i] != "-1") {
            RawNode rn = {treeVector[i], i+1};
            inStack.push(rn);
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