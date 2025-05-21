#include <stdio.h>
#define NODOS 6

void setMatriz(int matri[NODOS][NODOS]);

int main(){
    int matriz[NODOS][NODOS];
    
    setMatriz(matriz);

    //ingresamos la matriz adjayecente

    
}

void setMatriz(int matri[NODOS][NODOS]){
    //coloca la matriz en ceros
    for (int i = 0; i < NODOS; i++)
    {
        for (int j = 0; j < NODOS; j++)
        {
            matri[i][j] = 0;
        }
    }
}