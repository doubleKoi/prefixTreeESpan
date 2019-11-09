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
vector<ProjInst> ProjInst::Project(Tree& tree, string &label) {
    vector<ProjInst> result;
    for (auto iter = this->projInst.begin(); iter != this->projInst.end(); ++iter) {
        if (iter->label == label) {
            int beginIdx = tree.getIdxByPos(iter->pos);
            int p = tree.getIdxByPos((this->prefix)[0].pos);
            int endIdx = tree.getNodeByIdx(p).getMinusPos();

            for (auto newIter = iter; newIter != this->projInst.end(); ++newIter) {
                if ((*newIter).pos > beginIdx && (*newIter).pos < endIdx) {

                }
            }
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

void ProjInst::setPrefix(vector<ProjInstNode> &nodes) {
    for (ProjInstNode node: nodes) {
        this->prefix.push_back(node);
    }
}
