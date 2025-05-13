#include <stdio.h>

int main(){
    //Declaraciones
    int matriz[8][8];
    char nodos = 97;
    char abc = 97;

    int colocador = 0;
    int mov = 1;
    int delimitador = 8;

    int true = 1;

    //inicializar la matriz
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matriz[i][j] = 0;
        }
        
    }
    
    //toma de valores del usuario
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <= 7; j++)
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
            matriz[i][j] = colocador;
            matriz[j][i] = colocador;
            abc++;
    
        }
        delimitador--;
        true = 1;
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
    

}
        
        

    