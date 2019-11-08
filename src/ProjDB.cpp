//
// Created by Sherry Li on 2019/11/5.
//

#include <iostream>
#include <map>
#include <string>
#include "../include/ProjDB.h"
using namespace std;

ProjDB::ProjDB() = default;

vector<GrowElem> ProjDB::getFreqGEs(double minSup) {
    vector<GrowElem> freqGEs;
    map<string, int> GEFreq;
    for (ProjInst inst: this->projDB) {
        vector<GrowElem> GEs = inst.getGEs();
        for (GrowElem GE: GEs) {
            string str = GE.toString();
            if (GEFreq.find(str) != GEFreq.end()) {
                auto iter = GEFreq.find(str);
                iter->second += 1;
            } else {
                GEFreq.insert(make_pair(str, 1));
            }
        }
    }

    for (auto iter = GEFreq.begin(); iter != GEFreq.end(); ++iter) {
        if (iter->second >= minSup) {
            GrowElem growElem = GrowElem(iter->first);
            freqGEs.push_back(growElem);
        }
    }

}

//get length-1 projected database
ProjDB ProjDB::ProDB(vector<Tree> &trees, string freLabel) {
    ProjDB projDB = ProjDB();
    for (Tree tree: trees) {
        vector<ProjInst> instances = tree.Project(freLabel);
        projDB.insertProjInst(instances);
    }
    PreTree pt = PreTree(freLabel);
    projDB.setPattern(pt);

    return projDB;
}

void ProjDB::Fre(vector<Tree> &DB, PreTree &preTree, double minSup) {
    vector<GrowElem> freqGEs = this->getFreqGEs(minSup);
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

//TODO: get projected db from previous projected db
ProjDB ProjDB::ProDB(ProjDB &projDB, PreTree &preTree) {
    return ProjDB();
}

bool ProjDB::empty() {
    return this->projDB.empty();
}

void ProjDB::setPattern(PreTree &pt) {
    this->currentPattern = pt;
}

void ProjDB::insertProjInst(vector<ProjInst> &instances) {
    this->projDB.insert(this->projDB.end(), instances.begin(), instances.end());
}

