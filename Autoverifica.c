// Mondini Christian 5^F esercizi finiti ma non ottimizzati

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

void Copia(int sorgente[], int destinazione[], int dimensione, int dimensioned)
{
    int contatore = 0;
    for (int i = 0; i < dimensione; i++)
    {
        if (Frequenza(destinazione, dimensioned, sorgente[i]) == 0 || contatore==0)
        {
            destinazione[contatore] = sorgente[i];
            contatore++;
        }
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
    int dimensione2=dimensione; 

    if(doppi>0) {
        dimensione2 = dimensione2-(doppi-1);
    }
    
    return dimensione2;
}


void Swap(int doppio[], int num1, int num2, int dim2)
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
    int dim = 1 + rand() % 200; // dimensione casuale
    int array[dim];
    CreaArray(array, dim); // numeri casuali con possibili ripetizioni
    PrintArray(array, dim);
    int frequenza = 0;

    int dim2 = Ridimensiona(array, dim);
    int controllo[dim2];

    int contatore=0;

    for (int i = 0; i < dim; i++)
    {
        frequenza=Frequenza(array,dim,array[i]);
            if(Frequenza(controllo,dim,array[i])==0){
                controllo[contatore]=array[i];
                printf("Il valore %d compare %d volte nell'array.\n", controllo[contatore], frequenza);
                contatore++;
            }
        
    }

    
    int doppio[dim2];
    //printf("La dimensione e' %d\n", dim2);

    Copia(array, doppio, dim, dim2);

    //PrintArray(doppio, dim2);

    for (int i = 0; i < dim; i++)
    {
        for (int j = (i + 1); j < dim; j++)
        {
            if (Frequenza(array, dim, array[i]) < Frequenza(array, dim, array[j]))
            {
                Swap(doppio, array[i], array[j], dim2);
            }
        }
    }

    printf("Array con frequenze maggiori in cima:\n");

    PrintArray(doppio, dim2);

    int paridispari[dim2];
    Copia(array,paridispari,dim,dim2);

    PariDispari(paridispari, dim2);

    printf("Array con pari e dispari ordinati:\n");

    PrintArray(paridispari, dim2);

    return 0;
}
