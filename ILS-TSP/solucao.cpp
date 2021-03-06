#include <iostream>
#include <algorithm>
#include "solucao.h"

using namespace std;

extern double **matrizAdj;
extern int dimension;

Solucao::Solucao(){
    this->sequencia = {0};
    this->valorObj = 0;
}

Solucao::Solucao(vector<int> seq, double value){
    this->sequencia = seq;
    this->valorObj = value;
}

void Solucao::exibirSolucao(){
    for(int i = 0; i < this->sequencia.size() - 1; i++){
        cout << this->sequencia[i] << " -> ";
    }
    cout << this->sequencia.back() << "\n\n";
}

double Solucao::calcularValorObj(){
    this->valorObj = 0;
    for(int i = 0; i < this->sequencia.size() - 1; i++){
        valorObj += matrizAdj[this->sequencia[i]][this->sequencia[i+1]];
    }

    return valorObj;
}

vector<int> Solucao::escolher3NosAleatorios(){

    vector<int> subTourInicial;
    // ... +1 garante o intervalo [1, nº de cidades], sem isso o intervalo seria [0, nº de cidades -1]
    int noInicial = rand() % dimension + 1;
    
    subTourInicial.push_back(noInicial);

    for(int i = 0; i < 3; i++){
        
        int noAleatorio = rand() % dimension + 1;
        
        while((count(subTourInicial.begin(), subTourInicial.end(), noAleatorio) == 1)){
            noAleatorio = rand() % dimension + 1;
        }
        
        subTourInicial.push_back(noAleatorio);
    }

    subTourInicial.push_back(subTourInicial[0]);

    return subTourInicial;
}

vector<int> Solucao::nosRestantes(){
    vector<int> nosSobrando;
    for(int i = 1; i <= dimension; i++){
        if(count(this->sequencia.begin(), this->sequencia.end(), i) == 0){
            nosSobrando.push_back(i);
        }
    }

    return nosSobrando;
}