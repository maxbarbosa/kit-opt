#ifndef INFOINSERCAO_H
#define INFOINSERCAO_H
#include "solucao.h"
#include <iostream>
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
        vector<infoInsercao> calcularCustoInsercao(infoInsercao &, Solucao &, vector<int> &);
        double getCusto() {return this->custo;};
        static bool ordernarPorCusto(infoInsercao &, infoInsercao &);
        void imprimeInformacao() {cout << "(" << this->noInserido << ", " << this->arestaRemovida << ", " << this->custo << ")\n";};
        
        int getNoInserido() {return this->noInserido;};
        int getArestaRemovida() {return this->arestaRemovida;};
        double getCustoInfoInsercao() {return this->custo;};
        
        void setNoInserido(int no_) {this->noInserido =  no_;};
        void setArestaRemovida(int aresta_) {this->arestaRemovida = aresta_;};
        void setCusto(double custo_) {this->custo = custo_;};
};

#endif