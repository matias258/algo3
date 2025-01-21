#include <vector>
#include <map>
using namespace std;

/*
Backtracking TODAS LAS SOLUCIONES:

algoritmo BT(a,k)
    si a es solucion entonces
        procesar(a)
        retornar

    sino
        para cada a´ ∈ Sucesores(a, k)
            BT(a´, k + 1)
        fin para
    fin si
    retornar

Backtracking UNA SOLUCION:

algoritmo BT(a,k)
    si a es solucion entonces
    sol ← a
    encontro ← True

    sino
        para cada a´ ∈ Sucesores(a, k)
            BT(a´, k + 1)
            si encontro entonces
                retornar
            fin si
        fin para
    fin si
    retornar
*/


#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;


// 1. Conjunto de soluciones candidatas para C = {6, 12, 6} y k = 12.

// Usaremos Backtracking para obtener todas las combinaciones posibles.
// Ademas, ordenamos usando "sort"para evitar agregar combinaciones equivalentes (Ej {6, 12} y {12, 6})
void generarCombinaciones(vector<int>& C, vector<int>& combinacion, int indice, set<vector<int>>& resultado) {
    if (indice == C.size()) {
        if (!combinacion.empty()) {
            // Ordenar la combinación antes de agregarla al conjunto
            vector<int> copia = combinacion;
            sort(copia.begin(), copia.end());
            resultado.insert(copia);
        }
        return;
    }

    // No incluir el elemento actual
    generarCombinaciones(C, combinacion, indice + 1, resultado);

    // Incluir el elemento actual
    combinacion.push_back(C[indice]);
    generarCombinaciones(C, combinacion, indice + 1, resultado);
    combinacion.pop_back(); // backtracking
}

// 2. Conjunto de soluciones válidas para C = {6, 12, 6} y k = 12. Usando Backtracking de 0
void contarSubconjuntosConSuma(const vector<int>& C, int k, int start, int current_sum, int& count) {
    // Si la suma actual es igual a la suma objetivo, incrementa el contador
    if (current_sum == k) {
        count++;
    }
    // Recorre los elementos del conjunto a partir del índice 'start'
    for (int i = start; i < C.size(); i++) {
        // Llama recursivamente a la función con el siguiente elemento y la suma actualizada
        contarSubconjuntosConSuma(C, k, i + 1, current_sum + C[i], count);
    }
}

// 2.bis intentemos rehacer el 2 usando el backtracking ya hecho en el 1.

void contarSubconjuntosConSuma_2(vector<int>& C, vector<int>& combinacion, int indice, set<vector<int>>& resultado, int k) {
    if (indice == C.size()) {
        if (!combinacion.empty()) {
            // Ordenar la combinación antes de agregarla al conjunto
            vector<int> copia = combinacion;
            sort(copia.begin(), copia.end());
            if (accumulate(copia.begin(), copia.end(), 0) == k) {
                resultado.insert(copia);
            }
        }
        return;
    }

    // No incluir el elemento actual
    generarCombinaciones(C, combinacion, indice + 1, resultado);

    // Incluir el elemento actual
    combinacion.push_back(C[indice]);
    generarCombinaciones(C, combinacion, indice + 1, resultado);
    combinacion.pop_back(); // backtracking
}

int main() {
    vector<int> C = {6, 12, 6}; // Conjunto de ejemplo
    int k = 12; // Suma objetivo
    int count = 0; // Contador de subconjuntos
    vector<int> combinacion;
    set<vector<int>> resultado;

    generarCombinaciones(C, combinacion, 0, resultado);

    cout << "Combinaciones posibles:" << endl;
    for (const auto& comb : resultado) {
        cout << "{";
        for (size_t i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << "}" << endl;
    }

    contarSubconjuntosConSuma(C, k, 0, 0, count);
    cout << "Cantidad de subconjuntos con suma " << k << ": " << count << endl; // Salida esperada: 2


    contarSubconjuntosConSuma_2(C, combinacion, 0, resultado, k);
    cout << "Cantidad de subconjuntos con suma " << k << " (método 2): " << resultado.size() << endl; // Salida esperada: 2


    return 0;
}


