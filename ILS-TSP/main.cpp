#include "readData.h"
#include "solution.h"
#include "insertionInfo.h"
#include "ils.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

double ** matrizAdj; // matriz de adjacência
int dimension; // quantidade total de vértices

//void printData();

int main(int argc, char** argv) {

    readData(argc, argv, &dimension, &matrizAdj);

    vector<int> nodes;
    for(int i = 1; i <= dimension; i++){
        nodes.push_back(i);
    }
    nodes.push_back(1);

    Solution s1 = {nodes, 0};
    cout << s1.calculateAimValue(s1) << "\n";

    ILS ils1 = {s1, *matrizAdj};

    insertionInfo ins1= {1,1,0.0};

    ins1.calculateCostInsertion(s1, nodes);
    insertionInfo ins2 = {1,1,10};

}