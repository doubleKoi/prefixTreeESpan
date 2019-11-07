//
// Created by Sherry Li on 2019/11/5.
//

#include <iostream>
#include "../include/ProjDB.h"
using namespace std;

ProjDB::ProjDB() = default;

vector<GrowElem> ProjDB::getFreqGEs() {
    return vector<GrowElem>();
}

ProjDB ProjDB::ProDB(vector<Tree> &trees, PreTree &preTree) {
    return ProjDB();
}

void ProjDB::Fre(vector<Tree> &DB, PreTree &preTree, double minSup) {
    vector<GrowElem> freqGEs = this->getFreqGEs();
    if (freqGEs.empty()) {
        return;
    }

    for(GrowElem GE: freqGEs) {
        PreTree* newPreTree = preTree.grow(GE);
        cout << newPreTree->toString() << endl;

        ProjDB projectDB = ProjDB::ProDB(*(this), *newPreTree);
        projectDB.Fre(DB, *newPreTree, minSup);
    }
}

ProjDB ProjDB::ProDB(ProjDB &projDB, PreTree &preTree) {
    return ProjDB();
}

bool ProjDB::empty() {
    return this->projDB.empty();
}

