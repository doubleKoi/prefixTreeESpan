//
// Created by Sherry Li on 2019/11/4.
//

#ifndef PREFIXTREEESPAN_GROWELEM_H
#define PREFIXTREEESPAN_GROWELEM_H

#include <string>
using namespace std;

class GrowElem {
private:
    string label;           //label of the growth element
    int    attachedTo;      //position of the node in the prefix-tree that the GE is attached to

public:
    GrowElem(string label, int attachedTo);
    GrowElem(string GEStr);
    string getLabel();
    int getAttached();
    string toString();  //use GE string as key in map
    bool operator==(const GrowElem &GE) const;
    bool operator<(const GrowElem &GE) const;

};


#endif //PREFIXTREEESPAN_GROWELEM_H
