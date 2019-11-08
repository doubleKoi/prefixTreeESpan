//
// Created by Sherry Li on 2019/11/4.
//

#include "../include/GrowElem.h"

#include <utility>
#include <string>
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
    return this->label + "," + to_string(this->attachedTo);
}
