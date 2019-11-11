#define DATA "T1M"
#define MINSUP 0.02

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "include/Tree.h"
#include "include/PreTree.h"
#include "include/ProjDB.h"

using namespace std;

void prefixTreeESpanMiner(string dataPath, double minSup) {
    //read in data and construct tree database
    vector<Tree> DB;
    vector<string> allLabels;

    ifstream fin;
    fin.open(dataPath);
    string buffer;

    map<string, int> labelCount;
    for (int i = 0; !fin.eof(); ++i) {
        getline(fin, buffer, '\n');
        Tree tree = Tree(i, buffer);    //construct the tree
        DB.push_back(tree);

/*        //merge unique labels
        allLabels.insert(allLabels.end(),
                         tree.getUniqLabels().begin(),
                         tree.getUniqLabels().end());*/
        vector<string> uniqLabels = tree.getUniqLabels();
        for (string label: uniqLabels) {
            auto iter = labelCount.find(label);
            if (iter != labelCount.end()) {
                (iter->second)++;
            } else {
                labelCount.insert(make_pair(label, 1));
            }
        }
    }

    //get label frequencies
/*
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
*/

    //get frequent length-1 labels and begin mining
    //vector<string> freqLabels;
    cout<<"DB size: "<<DB.size()<<endl;
    clock_t startTime = clock();

    auto iter = labelCount.begin();
    for(;iter != labelCount.end(); ++iter) {
        if (iter->second >= minSup * DB.size()) {
            //freqLabels.push_back(iter->first);
            PreTree singlePreTree = PreTree(iter->first);   //construct length-1 prefix tree
            cout << iter->first << " -1" << endl;

            ProjDB projDB = ProjDB::ProDB(DB, iter->first);   //get <b -1> projected database
            projDB.Fre(DB, singlePreTree, minSup * DB.size());
        }
    }
    clock_t endTime = clock();
    cout << "time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

int main() {
    //string datasets[4] = {"CSlog", "D10", "F5", "T1M"};
    stringstream ss;
    ss << MINSUP;
    static std::ofstream ofs("../output/" + string(DATA) + "_" + ss.str() + ".txt");
    std::cout.rdbuf(ofs.rdbuf());
    double minSup = MINSUP;
    string dataPath = "../data/" + string(DATA) + ".data";
    prefixTreeESpanMiner(dataPath, MINSUP);
    return 0;
}