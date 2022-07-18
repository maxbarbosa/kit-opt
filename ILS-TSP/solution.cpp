#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

extern double **matrizAdj;
extern int dimension;

Solution::Solution(vector<int> seq, double value){
    sequence = seq;
    aimValue = value;
}

void Solution::showSolution(Solution &s){
    for(int i = 0; i < this->sequence.size() - 1; i++){
        cout << this->sequence[i] << " -> ";
    }
    cout << this->sequence.back() << "\n";
}

double Solution::calculateAimValue(Solution &s){
    this->aimValue = 0;
    for(int i = 0; i < this->sequence.size() - 1; i++){
        aimValue += matrizAdj[this->sequence[i]][this->sequence[i+1]];
    }

    return aimValue;
}