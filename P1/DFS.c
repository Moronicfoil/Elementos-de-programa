/*Andres Emilio Ibarra Paz IECSA04 11172*/

#include <stdio.h>

#define NODOS 7
#define NOVISITADO -1
#define VISITADO 1

void setArray(int array[NODOS]);
void DFS(int renglon, int matri[NODOS][NODOS], int array[NODOS]);

//funciones para imprimir matriz y arreglo 
void printMatriz(int matriz[NODOS][NODOS]);
void printArray(int array[NODOS]);

int main(){

    //ingresamos la matriz adjayecente
    int matriz[NODOS][NODOS] = {

    { 0, 1, 1, 0, 0, 0, 0 },
    { 1, 0, 0, 1, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 0, 1, 0 }  
    };

    //creamos el arreglo para saber cual hemos visitado
    int vistados[NODOS];
    
    //set up de visitados
    setArray(vistados);

    printMatriz(matriz);
    
    for (int i = 0; i < NODOS; i++)
    {
        if(vistados[i] == NOVISITADO){
            printf("estoy entrando al nodo %d \n",i);
            DFS(i, matriz, vistados);
        }
    }
    
}

//set el arreglo a no visitados todos los nodos
void setArray(int array[NODOS]){
    for (int i = 0; i < NODOS; i++)
    {
        array[i] = NOVISITADO;
    }
    
}
//realiza el algoritmo de DFS
void DFS(int renglon, int matri[NODOS][NODOS], int array[NODOS]){
    //marca el nodo como visitado e imprime el arreglo
    array[renglon] = VISITADO;
    printArray(array);
    
    printf("entre al nodo %d \n", renglon);

    for (int i = 0; i < NODOS; i++)
    {
        if((array[i] == NOVISITADO)&&(matri[renglon][i] == 1)){
           
            DFS(i, matri, array);
        }
    }
    printf("salio del nodo %d \n", renglon);
    
}

//imprime la matriz de adyacencia
void printMatriz(int matriz[NODOS][NODOS]){
    printf("Matriz \n");
    for (int i = 0; i < NODOS; i++)
    {
        for (int j = 0; j < NODOS; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}
//imprime el arreglo de los nodos visitados o no visitados
void printArray(int array[NODOS]){
    printf("Arreglo de los nodos visitados \n");
    for (int i = 0; i < NODOS; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
}