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
    int padre[V];    
    int clave[V];    
    int visitado[V]; 

    
    for (int i = 0; i < V; i++) {
        clave[i] = INT_MAX;
        visitado[i] = 0;
    }

    
    clave[0] = 0;    
    padre[0] = -1;  

    
    for (int i = 0; i < V - 1; i++) {
        int u = encontrarMinimo(clave, visitado);

        
        if (u == -1) {
            printf("\nError: El grafo no esta completamente conectado.\n");
            return;
        }

        visitado[u] = 1; 

        
        for (int v = 0; v < V; v++) {
            
            if (grafo[u][v] && !visitado[v] && grafo[u][v] < clave[v]) {
                
                padre[v] = u;
                clave[v] = grafo[u][v]; 
            }
        }
    }

    
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