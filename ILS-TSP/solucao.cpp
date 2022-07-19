#include <iostream>
#include <algorithm>
#include "solucao.h"

using namespace std;

extern double **matrizAdj;
extern int dimension;

Solucao::Solucao(){
    
    vector<int> nodes;
    for(int i = 1; i <= dimension; i++){
        nodes.push_back(i);
    }
    nodes.push_back(1);

    sequencia = nodes;
    valorObj = 0;
}

Solucao::Solucao(vector<int> seq, double value){
    sequencia = seq;
    valorObj = value;
}

void Solucao::exibirSolucao(){
    for(int i = 0; i < this->sequencia.size() - 1; i++){
        cout << this->sequencia[i] << " -> ";
    }
    cout << this->sequencia.back() << "\n\n";
}

double Solucao::calcularValorObjetivo(){
    this->valorObj = 0;
    for(int i = 0; i < this->sequencia.size() - 1; i++){
        valorObj += matrizAdj[this->sequencia[i]][this->sequencia[i+1]];
    }

    return valorObj;
}

vector<int> Solucao::escolher3NosAleatorios(){

    vector<int> randSubSequence;
    randSubSequence.push_back(1);

    int v = 0;
    for(int i = 0; i < 3; i++){
        
        v = rand() % dimension;

        while((count(randSubSequence.begin(), randSubSequence.end(), v) == 1) || v == 0){
            v = rand() % dimension;
        } 
        randSubSequence.push_back(v);

    }

    randSubSequence.push_back(1);

    return randSubSequence;
}

vector<int> Solucao::nosRestantes(){
    vector<int> rNodes;
    for(int i = 1; i <= dimension; i++){
        if(count(sequencia.begin(), sequencia.end(), i) == 0){
            rNodes.push_back(i);
        }
    }

    return rNodes;
}