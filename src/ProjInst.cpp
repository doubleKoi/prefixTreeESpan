//
// Created by Sherry Li on 2019/11/5.
//

#include "../include/ProjInst.h"

#include <utility>
using namespace std;

//TODO: implement Project()
/*ProjInst ProjInst::Project(string label) {

}*/

void ProjInst::setProjInst(vector<ProjInstNode> projInst) {
    for(ProjInstNode node: projInst){
        this->projInst.push_back(node);
    }
}

void ProjInst::setTranID(int tranID) {
    this->tranID = tranID;
}
