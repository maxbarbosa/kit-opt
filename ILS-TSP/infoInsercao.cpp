#include "infoInsercao.h"
#include "solucao.h"
#include <vector>
using namespace std;

extern double **matrizAdj;

infoInsercao::infoInsercao(){
    this->noInserido = 0;
    this->arestaRemovida = 0;
    this->custo = 0;
}

infoInsercao::infoInsercao(int no, int arestaRm, double c):
    noInserido{no}, arestaRemovida{arestaRm}, custo{c}
{};

vector<infoInsercao> infoInsercao::calcularCustoInsercao(Solucao &s, vector<int> &CL){
    infoInsercao insInfo;
    vector<infoInsercao> custoInsercao;

    int l = 0;
    for(int a = 0, b = 1; l < s.getTamSequencia() - 1; a++, b++){
        int i = s.getElementoSequencia(a);
        int j = s.getElementoSequencia(b);
        
        for(auto k : CL){
            insInfo.setNoInserido(k);
            insInfo.setArestaRemovida(a);
            insInfo.setCusto(matrizAdj[i][k] + matrizAdj[j][k] - matrizAdj[i][j]);

            custoInsercao.push_back(insInfo);
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