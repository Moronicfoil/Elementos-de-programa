#include <stdio.h>

#define NODOS 8

void sort(int array[]);
void printArray(int array[NODOS]);

int main(){
    int arreglo[NODOS] = {8,7,5,3,1,4,9,2};
    sort(arreglo);
    printArray(arreglo);

}

void printArray(int array[NODOS]){
    printf("Arreglo ordenado \n");
    for (int i = 0; i < NODOS; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort(int array[]){
    int ordenado = 0;
    do
    {
        ordenado = 0;
        for (int i = 0; i < NODOS-1; i++)
        {
           if(array[i] > array[i+1]){
            int c = array[i];
            array[i] = array[i+1];
            array[i+1] = c;
            ordenado = 1;
           }
        }
        
    } while (ordenado != 0);
    
}