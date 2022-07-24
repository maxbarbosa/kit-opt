#include "infoInsercao.h"
#include "solucao.h"
#include <vector>
using namespace std;

extern double **matrizAdj;

infoInsercao::infoInsercao(int no, int arestaRm, double c):
    noInserido{no}, arestaRemovida{arestaRm}, custo{c}
{};

vector<infoInsercao> infoInsercao::calcularCustoInsercao(infoInsercao &ins1, Solucao &s, vector<int> &CL){
    vector<infoInsercao> custoInsercao;

    int l = 0;
    for(int a = 0, b = 1; l < s.getTamSequencia() - 1; a++, b++){
        int i = s.getElementoSequencia(a);
        int j = s.getElementoSequencia(b);
        
        for(auto k : CL){
            ins1.setNoInserido(k);
            ins1.setArestaRemovida(a);
            ins1.setCusto(matrizAdj[i][k] + matrizAdj[j][k] - matrizAdj[i][j]);

            custoInsercao.push_back(ins1);
        }
        l++;
    }

    return custoInsercao;
}

bool infoInsercao::ordernarPorCusto(infoInsercao &i, infoInsercao &j){
    if(i.getCusto() < j.getCusto()){
        return true;
    }
    return false;
}