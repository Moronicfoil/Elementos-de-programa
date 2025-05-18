#include <stdio.h>


#define RENGLONES 8
#define COLUMNAS 8

int main(){
    //Declaraciones
    int matriz[RENGLONES][COLUMNAS];
    char nodos = 97;
    char abc = 97;

    int colocador = 0;
    int mov = 1;

    //inicializar la matriz
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matriz[i][j] = 0;
        }
        
    }
    
    //toma de valores del usuario
    for (int i = 0; i < RENGLONES -1; i++)
    {
        abc += mov;
        for (int j = 1 + i; j < COLUMNAS; j++)
        {
            //recoleccion de datos
            printf("Escriba los valores ponderados para %c, matriz de adyacencia [%c][%c]: \n", nodos, nodos, abc);
            scanf("%d", &colocador);
            matriz[i][j] = colocador;
            matriz[j][i] = colocador;
            abc++;
    
        }
        nodos++;
        abc = 97;
        mov++;
    }
    printf("\n");

    //imprime la matriz resultante 
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
        
    }

    return 0;
    

}

//n(n-1)/2