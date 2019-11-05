#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "include/Tree.h"
using namespace std;

void prefixTreeESpanMiner(string dataPath, double d) {
    ifstream fin(dataPath);

}

int main() {
    string datasets[4] = {"CSlog", "D10", "F5", "T1M"};
    for (string dataset: datasets) {
        string dataPath = "data/" + dataset + ".data";
        prefixTreeESpanMiner(dataPath, 0.5);
    }
    return 0;
}