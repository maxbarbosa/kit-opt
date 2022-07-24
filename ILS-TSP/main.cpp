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
    
    Solucao s;
    ILS ils1 = {s, *matrizAdj};
    cout << endl;
    ils1.Construcao().exibirSolucao();

    return 0;
}