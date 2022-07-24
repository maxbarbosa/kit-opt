#include "ils.h"
#include <cmath>
#include <iostream>
using namespace std;

ILS::ILS(Solucao &s, double *m) : solucao{s}, matriz{m} {};

Solucao ILS::Construcao(){
    this->solucao;
    this->solucao.setSequencia(this->solucao.escolher3NosAleatorios());

    vector<int> CL = this->solucao.nosRestantes();

    while(!CL.empty()){
        vector<infoInsercao> infoCusto;
        
        infoCusto = infoInsercao::calcularCustoInsercao(this->solucao, CL);
        sort(infoCusto.begin(), infoCusto.end(), infoInsercao::ordernarPorCusto);
    
        double alpha = (double) rand() / RAND_MAX;
        int selecionado = rand() % ((int) ceil(alpha * infoCusto.size()));

        this->solucao.inserirNaSolucao(infoCusto[selecionado].getNoInserido(), infoCusto[selecionado].getArestaRemovida() + 1);

        CL.erase(remove(CL.begin(), CL.end(), infoCusto[selecionado].getNoInserido()), CL.end());       
    }

    return this->solucao;       
}

void ILS::Perturbacao(){
    
}

void ILS::BuscaLocal(Solucao &){
    
}

bool ILS::bestImprovementSwap(Solucao &){
    return false;
}