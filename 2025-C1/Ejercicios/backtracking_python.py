import numpy as np
import pandas as pd

'''
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
'''

# Backtracking algoritmo para busqueda
def backtracking(A, x):
    encontro = False

    if np.size(A) == 0:
        return False
    
    elif A[0] == x:
        encontro = True
        return encontro
    
    else:
        A = np.delete(A, 0)
        backtracking(A, x)
    return False

print(backtracking([3,3,1,5,4], 2))