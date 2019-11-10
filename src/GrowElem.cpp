//
// Created by Sherry Li on 2019/11/4.
//

#include "../include/GrowElem.h"
#include "../include/Tree.h"

#include <utility>
#include <string>
#include <sstream>

using namespace std;

GrowElem::GrowElem(string label, int attachedTo) {
    this->label = move(label);
    this->attachedTo = attachedTo;
}

//Determine if two GEs are identical
bool GrowElem::operator==(const GrowElem &GE) const {
    return this->label == GE.label && this->attachedTo == GE.attachedTo;
}

string GrowElem::getLabel() {
    return this->label;
}

bool GrowElem::operator<(const GrowElem &GE) const {
    return this->label < GE.label || (this->label == GE.label && this->attachedTo < GE.attachedTo);
}

string GrowElem::toString() {
    stringstream ss;
    ss << this->attachedTo;
    string att = ss.str();
    return this->label + "," + att;
}

GrowElem::GrowElem(string GEStr) {
    vector<string> v = Tree::split(GEStr, ',');
    this->label = v[0];
    this->attachedTo = atoi(v[1].c_str());
}

int GrowElem::getAttached() {
    return this->attachedTo;
}
