#ifndef INSERTIONINFO_H
#define INSERTIONINFO_H
#include "solution.h"
#include <vector>
using namespace std;

class insertionInfo{
    private:
        int nodeInsert;
        int removedEdge;
        double cost;

    public:
        insertionInfo(int, int, double);
        ~insertionInfo() {};
        vector<insertionInfo> calculateCostInsertion(Solution &, vector<int> &);
};

#endif