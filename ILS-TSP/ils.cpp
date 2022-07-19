#include "ils.h"
#include <cmath>

ILS::ILS(Solucao &s, double *m) : solucao{s}, matriz{m} {};

//void ILS::Construcao(vector<infoInsercao> &infoCusto)
void ILS::Construcao(){
    Solucao s1 = {{0}, 0};
    s1.setSequencia(s1.escolher3NosAleatorios());

    vector<int> CL = s1.nosRestantes();

    while(!CL.empty()){
        infoInsercao ins1 = {0, 0, 0};
        vector<infoInsercao> infoCusto;
        
        infoCusto = ins1.calcularCustoInsercao(ins1, s1, CL);
        sort(infoCusto.begin(), infoCusto.end(), infoInsercao::ordernarInfoInsercao);
    
        double alpha = (double) rand() / RAND_MAX;
        int selecionado = rand() % ((int) ceil(alpha * infoCusto.size()));
        
        //Sendo (k, {i, j}) o par escolhido, retirar a aresta {i, j} de s' e inserir o vértice k entre i e j; 

        s1.inserirNaSolucao(s1, selecionado);

        int arestaARemover;

        for(int i = 0; i < CL.size(); i++){
            if(CL[i] == selecionado){
                arestaARemover = i;
                break;
            }
        }

        CL.erase(CL.begin() + arestaARemover);
        
    }

}

void ILS::Perturbacao(){
    
}

void ILS::BuscaLocal(Solucao &){
    
}

bool ILS::bestImprovementSwap(Solucao &){
    return false;
}