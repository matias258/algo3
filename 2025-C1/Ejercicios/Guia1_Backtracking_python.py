import numpy as np
import pandas as pd

''' Implementacion en c++ para posicionar n reinas sin que se toquen, en un tablero de n x n dimensiones

void search(int y) {
    if (y == n) {
        count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

'''
def bt(a, i):
    if i == N:
        if np.sum(a) <- P & np.sum(a) > mejorSuma:
            mejorSuma = np.sum(a)
    
    else:
        bt(np.concatenate(a, p))


# Ej 1: SumaSubconjuntosBT
# C ordenada arbitrariamente pero conocida
def SumaSubconjuntosBT_creciente(C, k):
    for i in range (0, np.size(C)):

        if np.size(C) == 0:
            return []
        
        elif sum(C) == k:
            return C
        
        else:
            C = np.delete(C, 0)
            SumaSubconjuntosBT_creciente(C, k)

    return []




def SumaSubconjuntosBT_decreciente(C, k):
    encontro = False

    if np.size(C) == 0:
        return []
    
    elif sum(C) == k:
        encontro = True
        return C
    
    else:
        C = np.delete(C, np.size(C)-1)
        SumaSubconjuntosBT_decreciente(C, k)
    return []

C, k = [6,12,6], 12
print(SumaSubconjuntosBT_creciente(C, k))



def SumaSubconjuntosBT(C, k):
    if (np.size(SumaSubconjuntosBT_decreciente) == 0 & 
        np.size(SumaSubconjuntosBT_creciente)==0):
        return []
    

