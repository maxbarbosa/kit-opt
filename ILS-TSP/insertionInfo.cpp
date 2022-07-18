#include "insertionInfo.h"
#include "solution.h"
#include <vector>
using namespace std;

extern double **matrizAdj;

insertionInfo::insertionInfo(int node, int rmEdge, double c):
    nodeInsert{node}, removedEdge{rmEdge}, cost{c}
{};


vector<insertionInfo> insertionInfo::calculateCostInsertion(Solution &s, vector<int> &CL){
    vector<insertionInfo> teste;
    return teste;
}

/*
vector<insertionInfo> insertionInfo::calculateCostInsertion(Solution &s, vector<int> &CL){
    vector<insertionInfo> insertionCost((s.getSequenceSize() - 1)  * CL.size());

    int l = 0;
    for(int a = 0, b = 1; l < s.getSequenceSize() - 1; a++, b++){
        int i = s.getElement(a);
        int j = s.getElement(b);
        
        for(auto k : CL){
            insertionCost[l].cost = matrizAdj[i][k] + matrizAdj[j][k] - matrizAdj[i][j];
            insertionCost[l].nodeInsert = k;
            insertionCost[l].removedEdge = a;
            l++;
        }
    }

    return insertionCost;
}
*/