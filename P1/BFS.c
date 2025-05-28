#include <stdio.h>

#define NODOS 4
#define NOVISITADO -1
#define VISITADO 1
#define VISTO 2
#define SIGUIENTE 3

void setArray(int array[NODOS]);
void BFS(int renglon, int matri[NODOS][NODOS], int array[NODOS]);
void recorridoCola(int array[NODOS]);

//funciones para imprimir matriz y arreglo 
void printMatriz(int matriz[NODOS][NODOS]);
void printArray(int array[NODOS]);

int main(){

    //ingresamos la matriz adjayecente
    int matriz[NODOS][NODOS] = {
    //0  1  2  3
    { 0, 1, 1, 0 }, // 0
    { 1, 0, 0, 0 }, // 1
    { 1, 0, 0, 1 }, // 2
    { 0, 0, 1, 0 }  // 3
    };

    //creamos el arreglo para saber cual hemos visitado
    int vistados[NODOS];
    
    

    //set up de visitados
    setArray(vistados);

    printMatriz(matriz);
    
    int cont = 0;
    //realiza el movimiento entre nodos
    while (cont < 1)
    {
        BFS(cont, matriz, vistados);
        cont++;
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
void BFS(int renglon, int matri[NODOS][NODOS], int array[NODOS]){
    //marca el nodo como visitado e imprime el arreglo
    array[renglon] = VISITADO;
    printArray(array);
    
    printf("entre al nodo %d \n", renglon);

    for (int i = 0; i < NODOS; i++)
    {
        if((array[i] == NOVISITADO)&&(matri[renglon][i] == 1)){
           
            array[i] = VISTO;
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

void recorridoCola(int array[NODOS]){
    for (int i = 0; i < NODOS; i++)
    {
        if (array[i] == VISTO)
        {
            array[i] = SIGUIENTE;
        }
        
    }
    
}