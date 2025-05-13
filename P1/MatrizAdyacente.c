#include <stdio.h>

int main(){
    //Declaraciones
    int matriz[8][8];
    char nodos = 97;
    char abc = 97;

    int colocador = 0;
    int mov =1;
    int delimitador = 8;

    int true = 1;

    //inicializar la matriz
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < j; j++)
        {
            matriz[i][j] = 0;
        }
        
    }

    //toma de valores del usuario
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < delimitador; j++)
        {
            //nos saltamos los valores que ya colocamos 
            if(true ==1){
                abc += mov;
                j += mov;
                true = 0;
            }
            
            //recoleccion de datos
            printf("Escriba los valores ponderados para %c, matriz de adyacencia [%c][%c]: \n", nodos, nodos, abc);
            scanf("%d", &colocador);
            matriz[i][j+ mov] = colocador;
            matriz[j+mov][i] = colocador;
            abc++;
    
        }
        delimitador--;
        true = 1;
        nodos++;
        abc = 97;
        mov++;
    }

}
        
        

    