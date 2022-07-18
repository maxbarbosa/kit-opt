#ifndef ILS_H
#define ILS_H
#include "readData.h"
#include "solution.h"
#include "insertionInfo.h"

using namespace std;

class ILS{
    private:
        Solution solution;
        double *matriz;

    public:
        ILS(Solution &, double *);
        ~ILS() {};
        void Construction(insertionInfo &);
        void Disturbance();
        void LocalSearch(Solution &);
        bool bestImprovementSwap(Solution &);

};

#endif