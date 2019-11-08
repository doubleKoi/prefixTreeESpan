//
// Created by Sherry Li on 2019/11/5.
//

#include "../include/ProjInst.h"

#include <utility>
using namespace std;

void ProjInst::setProjInst(vector<ProjInstNode> &projInst) {
    for(const ProjInstNode& node: projInst){
        this->projInst.push_back(node);
    }
}

//TODO: implement Project()
ProjInst ProjInst::Project(string label) {
    return ProjInst();
}

ProjInst::ProjInst(int tranID) {
    this->tranID = tranID;
}

//TODO: implement getGEs()
vector<GrowElem> ProjInst::getGEs() {
    vector<GrowElem> GEs;

    for (ProjInstNode node: this->projInst) {
        GrowElem GE = GrowElem(node.label, node.attachedTo);

    }
    return GEs;
}
