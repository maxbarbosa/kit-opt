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
        void inserirNaSolucao(Solucao &s, int no) {sequencia.push_back(no);};
        double calcularValorObjetivo();
        int getTamSequencia() {return sequencia.size();};
        int getElementoSequencia(int pos) {return sequencia[pos];};
        vector<int> setSequencia(vector<int> novaSequencia) {return sequencia = novaSequencia;};
        vector<int> escolher3NosAleatorios();
        vector<int> nosRestantes();
};

#endif