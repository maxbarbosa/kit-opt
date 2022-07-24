#ifndef SOLUCAO_H
#define SOLUCAO_H
#include <vector>
using namespace std;

class Solucao{
    private:
        vector<int> sequencia;
        double valorObj;

    public:
        Solucao();
        Solucao(vector<int>, double);
        ~Solucao() {};
        void exibirSolucao();
        void inserirNaSolucao(int no, int pos) {this->sequencia.insert(this->sequencia.begin() + pos, no);};
        double calcularValorObjetivo();
        int getTamSequencia() {return this->sequencia.size();};
        int getElementoSequencia(int pos) {return this->sequencia[pos];};
        vector<int> setSequencia(vector<int> novaSequencia) {return this->sequencia = novaSequencia;};
        vector<int> escolher3NosAleatorios();
        vector<int> nosRestantes();
};

#endif