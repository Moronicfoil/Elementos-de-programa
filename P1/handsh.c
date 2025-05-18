#include "stdio.h"

void validen_entero(int *);
void crear_matriz(int total, int matri[total][total]);
void desicion_formula_conteo(int total, int matri[total][total]);
void print_matriz(int n, int matri[n][n]);

int main()
{
    // tamaño de la matriz
    int n = 0;
    // total de saludos
    int total_saludos = 0;

    printf("Introducir numero de personas: \n");
    validen_entero(&n);

    int matriz[n][n];
    crear_matriz(n, matriz);
    print_matriz(n, matriz);
    desicion_formula_conteo(n, matriz);

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    

    return 0;
}
// funcion para rellenar la matriz
void crear_matriz(int total, int matri[total][total])
{

    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            if (i == j)
            {
                matri[i][j] = 0;
            }
            else
            {
                matri[i][j] = 1;
            }
        }
    }
}
// validación de que se coloque un entero
void validen_entero(int *x)
{
    int r;
    while (((r = scanf("%d", x)) != 1) && (*x >= 0))
    {
        printf("Error. Introducir numero entero ");
        while (getchar() != '\n')
            ; // Limpieza de buffer
        // En caso de introduccion erronea de datos
    }
}
// funcion para la impresion de la matriz
void print_matriz(int n, int matri[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d \t", matri[i][j]);
        }
        printf("\n");
    }
}
// seleccion de forma de conteo
void desicion_formula_conteo(int total, int matri[total][total])
{

    printf("Seleccione el metodo a utilizar: \n");
    printf("1. Fuerza bruta.\n");
    printf("2. Formula de Gauss\n");

    int total_saludos = 0;
    int selec;
    validen_entero(&selec);

    switch (selec)
    {
    case 1:
        for (int i = 0; i < total; i++)
        {
            for (int j = i + 1; j < total; j++)
            {
                if (matri[i][j] == 1)
                {
                    total_saludos++;
                }
            }
        }
        
        printf("El total de saludos es: %d\n", total_saludos);

        break;

    case 2:
        total_saludos = total*(total-1)/2;
        printf("El total de saludos es: %d\n", total_saludos);
        break;

    default:
        printf("No Seleciono nada");
        break;
    }
}