//
// Created by Sherry Li on 2019/11/5.
//

#ifndef PREFIXTREEESPAN_PROJDB_H
#define PREFIXTREEESPAN_PROJDB_H

#include <vector>
#include "ProjInst.h"
#include "GrowElem.h"
using namespace std;

class ProjDB {
private:
    vector<ProjInst> projDB;

public:
    ProjDB();
    vector<GrowElem> getFreqGEs();
    static ProjDB getProjDB();
};


#endif //PREFIXTREEESPAN_PROJDB_H
