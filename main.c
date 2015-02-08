#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void heapSort(int arreglo[], int n);
void heapify(int arreglo[], int n);
void siftdown(int arreglo[], int inicio, int fin);
void intercambiar(int *a, int *b);

int main()
{
    FILE *fp = fopen("arreglo.in", "r");
    time_t t;
    int n,i;

    srand((unsigned) time(&t));

    fscanf(fp,"%d", &n);

    int arreglo[n];

    for(i = 0; i < n; i++)
    {
        arreglo[i] = rand() % 100;
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", arreglo[i]);
    }

    printf("\n");

    heapSort(arreglo, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", arreglo[i]);
    }

    return 0;
}

void heapSort(int arreglo[], int n)
{
    int fin;
    heapify(arreglo, n);
    fin = n - 1;
    while(fin > 0)
    {
        intercambiar(&arreglo[0], &arreglo[fin]);
        siftdown(arreglo, 0, fin);
        fin--;
    }
}

void heapify(int arreglo[], int n)
{
    int inicio;
    inicio = (n-2)/2;
    while(inicio >= 0)
    {
        siftdown(arreglo, inicio, n);
        inicio--;
    }
}

void siftdown(int arreglo[], int inicio, int fin)
{
    int padre, hijo, band;
    padre = inicio;
    hijo = (padre * 2) + 1;
    band = 1;
    while(band == 1 && hijo < fin)
    {
        if(hijo + 1 < fin && arreglo[hijo] < arreglo[hijo + 1])
            hijo++;
        if(arreglo[padre] < arreglo[hijo])
        {
            intercambiar(&arreglo[padre], &arreglo[hijo]);
            padre = hijo;
        }else
        band = 0;
        hijo = (padre * 2) + 1;
    }
}

void intercambiar(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

