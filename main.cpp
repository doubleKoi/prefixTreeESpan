#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include "include/Tree.h"
#include "include/PreTree.h"
#include "include/ProjDB.h"

using namespace std;

void prefixTreeESpanMiner(string dataPath, double minSup) {
    //read in data and construct tree database
    vector<Tree> DB;
    vector<string> allLabels;

    ifstream fin(dataPath);
    string buffer;

    for (int i = 0; !fin.eof(); ++i) {
        getline(fin, buffer);
        Tree tree = Tree(i, buffer);    //construct the tree
        DB.push_back(tree);

        //merge unique labels
        allLabels.insert(allLabels.end(),
                         tree.getUniqLabels().begin(),
                         tree.getUniqLabels().end());
    }

    //get label frequencies
    sort(allLabels.begin(), allLabels.end());
    map<string, int> labelCount;

    labelCount.insert(make_pair(*(allLabels.begin()), 1));

    for (auto iter = allLabels.begin(); iter != allLabels.end();) {
        string lastLabel = *iter;
        iter++;
        if (*iter != lastLabel) {
            labelCount.insert(make_pair(*iter, 1));
        } else {
            if (labelCount.find(lastLabel) != labelCount.end()) {
                (labelCount.find(lastLabel))->second += 1;
            }
        }
    }

    //get frequent length-1 labels and begin mining
    //vector<string> freqLabels;
    auto iter = labelCount.begin();
    for(;iter != labelCount.end(); ++iter) {
        if (iter->second >= minSup) {
            //freqLabels.push_back(iter->first);
            PreTree singlePreTree = PreTree(iter->first);   //construct length-1 prefix tree
            cout << iter->first << endl;

            ProjDB projDB = ProjDB::ProDB(DB, iter->first);   //get <b -1> projected database
            projDB.Fre(DB, singlePreTree, minSup);
        }
    }
}

int main() {
    string datasets[4] = {"CSlog", "D10", "F5", "T1M"};
    for (string dataset: datasets) {
        string dataPath = "data/" + dataset + ".data";
        prefixTreeESpanMiner(dataPath, 0.5);
    }
    return 0;
}