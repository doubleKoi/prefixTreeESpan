//
// Created by Sherry Li on 2019/11/5.
//

#include "../include/ProjInst.h"
#include <algorithm>

#include <utility>
using namespace std;

void ProjInst::setProjInst(vector<ProjInstNode> &projInst) {
    for(const ProjInstNode& node: projInst){
        this->projInst.push_back(node);
    }
}

//TODO: implement Project()
vector<ProjInst> ProjInst::Project(Tree& tree, PreTree &preTree) {
    ProjInst result = ProjInst(this->tranID);
    for (ProjInstNode node: this->projInst) {
        if (node.label == label) {

        }
    }
}

ProjInst::ProjInst(int tranID) {
    this->tranID = tranID;
}

vector<GrowElem> ProjInst::getGEs() {
    vector<GrowElem> GEs;
    vector<string> GEStrs;

    for (ProjInstNode node: this->projInst) {
        GrowElem GE = GrowElem(node.label, node.attachedTo);
        string key = GE.toString();
        auto iter = find(GEStrs.begin(), GEStrs.end(), key);
        if (iter == GEStrs.end()) {
            GEs.push_back(GE);
            GEStrs.push_back(key);
        }
    }
    return GEs;
}
