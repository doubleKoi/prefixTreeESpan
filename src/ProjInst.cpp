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

vector<ProjInst> ProjInst::Project(Tree& tree, string &label) {
    vector<ProjInst> result;
    for (auto iter = this->projInst.begin(); iter != this->projInst.end(); ++iter) {
        vector<ProjInstNode> nodes;
        if (iter->label == label) {
            int beginIdx = tree.getIdxByPos(iter->pos);
            int p = tree.getIdxByPos((this->prefix)[0].pos);
            int endIdx = tree.getNodeByIdx(p).getMinusPos();

            for (auto newIter = iter+1; newIter != this->projInst.end(); ++newIter) {
                if ((*newIter).pos > beginIdx && (*newIter).pos < endIdx) {
                    int attached = getAttachedTo(tree, this->prefix, (*newIter).pos);
                    ProjInstNode nd = {(*newIter).label, (*newIter).pos, attached};
                    nodes.push_back(nd);
                }
            }
            ProjInst newInst = ProjInst(this->tranID);
            newInst.setProjInst(nodes);
            result.push_back(newInst);
        }
    }
    return result;
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

int ProjInst::getAttachedTo(Tree &tree, vector<ProjInstNode> &prefix, int pos) {
    int result = 0;
    for (int i = 0; i < prefix.size(); i++) {
        ProjInstNode node = prefix[i];
        int idx = tree.getIdxByPos(node.pos);
        int minusPos = tree.getNodeByIdx(idx).getMinusPos();

        if (pos < minusPos && pos > node.pos) {
            result = i;
        } else {
            continue;
        }
    }

    return result;
}

int ProjInst::getTranID() {
    return this->tranID;
}
