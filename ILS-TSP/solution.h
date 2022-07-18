#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
using namespace std;

class Solution{
    private:
        vector<int> sequence;
        double aimValue;

    public:
        Solution(vector<int>, double);
        ~Solution () {};
        void showSolution(Solution &);
        double calculateAimValue(Solution &);
        int getSequenceSize() {return sequence.size();};
        int getElement(int pos) {return sequence[pos];};
};

#endif