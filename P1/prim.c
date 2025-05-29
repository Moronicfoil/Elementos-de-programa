/*Andres Emilio Ibarra Paz IECSA04 11172*/

#include <stdio.h>
/*
limits define los limites de implementacion de los tipos de datos en C, 
un ejemplo, es el INT_MAX, este define el valor maximo que puede tener un dato 
de tipo int
*/
#include <limits.h> 

//define nuestro numero de nodos en el programa
#define V 5  

/*
funcion para encontrar el renglon siguiente.
devuelve el renglon del nodo de menor peso sin visitar
*/
int encontrarMinimo(int clave[], int visitado[]) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!visitado[v] && clave[v] < min) {  
            min = clave[v];
            minIndex = v;
        }
    }
    return minIndex;
}


void imprimirMST(int padre[], int grafo[V][V]) {
    printf("\nAristas en el arbol de expansion minima:\n");
    printf("Nodo 1 - Nodo 2 \t Peso\n");
    int costoTotal = 0;
    
    for (int i = 1; i < V; i++) {
        printf("  %d   -   %d   \t\t  %d\n", padre[i], i, grafo[i][padre[i]]);
        costoTotal += grafo[i][padre[i]];
    }
    
    printf("\nCosto total del MST: %d\n", costoTotal);
}


void prim(int grafo[V][V]) {
    /*
    se crean 3 arreglos para utilizar durante el codigo
    padre -- este arreglo sirve para conocer el padre de un nodo
    clave -- en este arreglo se guarda los pesos de los nodos
    vistiados -- este sirve para llevar un conteo de los nodos visitados y los que falta, tambien para evitar 
                ciclos dentro del algoritmo
    */
    int padre[V];    
    int clave[V];    
    int visitado[V]; 

    /*
    se inicializa el arreglo de visitados con ceros 
    y el arreglo de clave con el valor máximo que puede tener un int
    */
    for (int i = 0; i < V; i++) {
        clave[i] = INT_MAX;
        visitado[i] = 0;
    }

    //Eleccion arbitraria del nodo inicial
    clave[0] = 0;
    //el primer nodo no tiene padre, por lo tanto es igual a
    padre[0] = -1;  

    //ciclo para recorre el grafo
    for (int i = 0; i < V - 1; i++) {
        //encuentra el nodo con la arista de menor peso, con datos que se actualiza como la lista de visitados y la de claves
        //regresa el renglon donde se encontro el nodo con menor peso
        int u = encontrarMinimo(clave, visitado);

        
        if (u == -1) {
            printf("\nError: El grafo no esta completamente conectado.\n");
            return;
        }

        /*
        se marca como vistado el renglon donde se encontro la arista 
        */
        visitado[u] = 1; 

        //si no esta vistadod da 1, si ya esta vistado me da un 0
        for (int v = 0; v < V; v++) {

            /*
            revisa ciertas condicinales para actualizar la lista de padre y clave
            1- existe una arista entre u y v
            2- v no ha sido vistado anteriormente 
            3- el peso de la arista de u a v es menor que la clave de v
            de ser cierto todo, se accede al if, en el cual se actualizan valores
            */
            if (grafo[u][v] && !visitado[v] && grafo[u][v] < clave[v]) {
                
                padre[v] = u;
                clave[v] = grafo[u][v]; 
            }
        }
    }

    //imprime el recorrido que realizo el algoritmo de Prim
    imprimirMST(padre, grafo);
}

// Función principal
int main() {
    
    int grafo[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("=== Algoritmo de Prim para Árbol de Expansión Mínima ===\n");
    prim(grafo);

    return 0;
}