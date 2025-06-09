/*Andres Emilio Ibarra Paz IECSA04 11172*/

#include <stdio.h>

#define NODOS 7
#define NOVISITADO -1
#define VISITADO 1
#define VISTO 2
#define SIGUIENTE 3

//funcion para colocar todos los valores como no vistado 
void setArray(int array[NODOS]);

//funcion para realizar el BFS
void BFS(int renglon, int matri[NODOS][NODOS], int array[NODOS]);

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
    
    BFS(0,matriz,vistados);

    return 0;
    
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
    //arreglo imitacion a la cola
    int cola[NODOS];
    //el inicio y el final de la cola
    int primero = 0; int ultimo = 0;

    //marca el nodo como visitado e imprime el arreglo
    array[renglon] = VISITADO;
    cola[ultimo] = renglon;
    ultimo++;
    printArray(array);

    //nos movemos por la cola, siempre que el primero sea diferente al ultimo
    while (primero!=ultimo)
    {
        int temp = cola[primero];
        primero++;
        printf("Nodo visitado: %d\n", temp);

         for (int i = 0; i < NODOS; i++) {
            if (matri[temp][i] == 1 && array[i] == NOVISITADO) {
                cola[ultimo] = i; 
                ultimo++; 
                //marcamos el nodo como vistado
                array[i] = VISITADO;
            }
        }
        printArray(array);

    }
    
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
