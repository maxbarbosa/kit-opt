#ifndef INFOINSERCAO_H
#define INFOINSERCAO_H
#include "solucao.h"
#include <vector>
using namespace std;

class infoInsercao{
    private:
        int noInserido;
        int arestaRemovida;
        double custo;

    public:
        infoInsercao(int, int, double);
        ~infoInsercao() {};
        vector<infoInsercao> calcularCustoInsercao(infoInsercao &,Solucao &, vector<int> &);
        double getCusto() {return custo;};
        static bool ordernarInfoInsercao(infoInsercao &, infoInsercao &);
        void setNoInserido(int no_) {noInserido =  no_;};
        void setArestaRemovida(int aresta_) {arestaRemovida = aresta_;};
        void setCusto(double custo_) {custo = custo_;};
};

#endif