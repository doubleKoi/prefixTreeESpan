//
// Created by Sherry Li on 2019/11/5.
//

#ifndef PREFIXTREEESPAN_PROJDB_H
#define PREFIXTREEESPAN_PROJDB_H

#include <vector>
#include "Tree.h"
#include "PreTree.h"
#include "ProjInst.h"
#include "GrowElem.h"
using namespace std;

class ProjDB {
private:
    vector<ProjInst> projDB;
    PreTree currentPattern;

public:
    ProjDB();
    vector<GrowElem> getFreqGEs(double minSup);
    static ProjDB ProDB(vector<Tree> &trees, string freLabel);
    static ProjDB ProDB(ProjDB &projDB, PreTree &preTree);
    bool empty();
    void Fre(vector<Tree> &DB, PreTree &preTree, double minSup);
    void setPattern(PreTree &pt);
    void insertProjInst(vector<ProjInst> &instances);
};


#endif //PREFIXTREEESPAN_PROJDB_H
