#include "readData.h"
#include "solucao.h"
#include "infoInsercao.h"
#include "ils.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

double ** matrizAdj; // matriz de adjacência
int dimension; // quantidade total de vértices

int main(int argc, char** argv) {
    srand(time(NULL));

    readData(argc, argv, &dimension, &matrizAdj);

    Solucao s1;
    s1.exibirSolucao();
    cout << s1.calcularValorObjetivo() << "\n";
    cout << s1.getElementoSequencia(2) << endl;
    cout << s1.getTamSequencia() << "\n";

    Solucao s2 = {{5, 4, 3}, 10};
    s2.exibirSolucao();
    //geração de 3 nós aleatórios do início da construção deu cerTO
    s2.setSequencia(s2.escolher3NosAleatorios());
    s2.exibirSolucao();
    vector<int> teste;
    teste = s2.nosRestantes();

    for(auto k : teste){
        cout << k << " -> ";
    }
}