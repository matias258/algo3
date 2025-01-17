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



