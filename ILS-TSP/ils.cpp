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

void ILS::BuscaLocal(){
    
}

bool ILS::bestImprovementSwap(){
    /*
    this->solucao;

    double bestDelta = 0;

    int best_i = 0, best_j = 0;

    for(int i = 1; i < solucao.getTamSequencia() - 1; i++){
        for(int j = i + 1; j < solucao.getTamSequencia() - 1; j++){
            double delta = calculateSwapCost(i, j);
            if(delta < bestDelta){
                bestDelta = delta;
                best_i = i;
                best_j = j;
            }
        }
    }

    if(bestDelta < 0){
        swap(solucao.getElementoSequencia(best_i), solucao.getElementoSequencia(best_j));
        solucao.setValorObj(solucao.calcularValorObj() - delta);
        return true;
    }
    */

    return false;
}