#ifndef ILS_H
#define ILS_H
#include "readData.h"
#include "solucao.h"
#include "infoInsercao.h"
#include <algorithm>

using namespace std;

class ILS{
    private:
        Solucao solucao;
        double *matriz;

    public:
        ILS(Solucao &, double *);
        ~ILS() {};
        Solucao Construcao();
        void Perturbacao();
        void BuscaLocal(Solucao &);
        bool bestImprovementSwap(Solucao &);

};

#endif