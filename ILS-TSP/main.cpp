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

    Solucao s1 = {{0}, 0};
    s1.setSequencia(s1.escolher3NosAleatorios());
    s1.exibirSolucao();

    vector<int> CL = s1.nosRestantes();
    for(auto cl : CL){
        cout << cl << " -> ";
    }

    cout << "\n";
    Solucao s = {{0}, 0};
    ILS ils1 = {s, *matrizAdj};
    cout << endl;
    ils1.Construcao().exibirSolucao();

    return 0;
}