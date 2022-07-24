#include "ils.h"
#include <cmath>
#include <iostream>
using namespace std;

ILS::ILS(Solucao &s, double *m) : solucao{s}, matriz{m} {};

Solucao ILS::Construcao(){
    this->solucao = {{0}, 0};
    this->solucao.setSequencia(this->solucao.escolher3NosAleatorios());

    vector<int> CL = this->solucao.nosRestantes();

    while(!CL.empty()){
        infoInsercao ins1 = {0, 0, 0};
        vector<infoInsercao> infoCusto;
        
        infoCusto = ins1.calcularCustoInsercao(ins1, this->solucao, CL);
        sort(infoCusto.begin(), infoCusto.end(), infoInsercao::ordernarPorCusto);
    
        double alpha = (double) rand() / RAND_MAX;
        int selecionado = rand() % ((int) ceil(alpha * infoCusto.size()));

        this->solucao.inserirNaSolucao(infoCusto[selecionado].getNoInserido(), infoCusto[selecionado].getArestaRemovida() + 1);

        int k = 0;

        for(int i = 0; i < CL.size(); i++){
            if(CL[i] == infoCusto[selecionado].getNoInserido()){
                k = i;
                break;
            }
        }

        CL.erase(CL.begin() + k);
        
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