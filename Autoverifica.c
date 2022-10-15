//Mondini Christian 5^F esercizi finiti ma non ottimizzati


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void CreaArray(int array[], int dimensione)
{
    int num;
    for (int i = 0; i < dimensione; i++)
    {
        num = 1 + rand() % 500;
        array[i] = num;
    }
}

void PrintArray(int array[], int dimensione)
{
    for (int i = 0; i < dimensione; i++)
    {
        printf("[%d]: %d\n", i, array[i]);
    }
}

int Frequenza(int array[], int dimensione, int numero)
{
    int frequenza = 0;
    for (int i = 0; i < dimensione; i++)
    {
        if (array[i] == numero)
        {
            frequenza++;
        }
    }
    return frequenza;
}

void Copia(int sorgente[], int destinazione[], int dimensione)
{

    for (int i = 0; i < dimensione; i++)
    {
        /*if (Frequenza(destinazione, dimensioned, sorgente[i]) > 1)
        {
        }
        else
        {

            destinazione[i] = sorgente[i];
        }*/
        destinazione[i] = sorgente[i];
    }
}

void PariDispari(int array[], int dimensione)
{
    for (int i = 0; i < dimensione; i++)
    {
        for (int j = (i + 1); j < dimensione; j++)
        {
            if (array[i] % 2 == 0 && array[j] % 2 == 0)
            { // se trattiamo numeri pari
                if (array[i] > array[j])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
            else if (array[i] % 2 != 0 && array[j] % 2 != 0)
            { // se trattiamo dispari
                if (array[i] < array[j])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}



//WORK IN PROGRESS
int Ridimensiona(int array[], int dimensione)
{
    int doppi = 0;
    for (int i = 0; i < dimensione; i++)
    {
        for (int j = (i + 1); j < dimensione; j++)
        {
            if (array[i] == array[j])
            {
                doppi++;
            }
        }
    }
    int dimensione2 = dimensione - doppi;
    return dimensione2;
}


//WORK IN PROGRESS
void Swap(int doppio[], int num1, int num2,int dim2)
{
    for (int i = 0; i < dim2; i++)
    {
        for (int j = (i + 1); j < dim2; j++)
        {
            if (doppio[i] == num1 && doppio[j] == num2)
            {

                int temp = doppio[i];
                doppio[i] = doppio[j];
                doppio[j] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int dim = 1 + rand() % 50; // dimensione casuale
    int array[dim];
    CreaArray(array, dim); // numeri casuali con possibili ripetizioni
    PrintArray(array, dim);
    int frequenza = 0;

    for (int j = 0; j < dim; j++)
    {
        frequenza = Frequenza(array, dim, array[j]);
        printf("Il valore %d compare %d volte nell'array.\n", array[j], frequenza);
    }

    /*int dim2 = Ridimensiona(array, dim);
    int doppio[dim2];*/

    int doppio[dim];
    Copia(array, doppio, dim);

    for (int i = 0; i < dim; i++)
    {
        for (int j = (i + 1); j < dim; j++)
        {
            if (Frequenza(doppio, dim, doppio[i]) < Frequenza(doppio, dim, doppio[j]))
            {

                int temp = doppio[i];
                doppio[i] = doppio[j];
                doppio[j] = temp;
            }
        }
    }


    printf("Array con frequenze maggiori in cima:\n");

    PrintArray(doppio, dim);

    PariDispari(array, dim);

    printf("Array con pari e dispari ordinati:\n");

    PrintArray(array, dim);

    return 0;
}