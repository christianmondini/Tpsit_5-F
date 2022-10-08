#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 233
#define MIN 1

void Insertarray(int array[], int length)
{
    int controllo = 0;
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        // srand(time(NULL));
        result = (rand() % (MAX - MIN)) + MIN;
        array[i] = result;
        if (i > 1)//Se sono almeno 2 numeri
        {
            for (int j = 0; j < (i - 1); j++)//controllo che non ci siano doppioni ed in caso genero un altro numero dicerso da tutti gli altri
            {
                if (array[j] == array[i])
                {
                    // printf("Generazione");
                    controllo = (rand() % (MAX - MIN)) + MIN;
                    array[i] = controllo;
                    j = 0;
                }
            }
        }
        else if (i == 1)// Se sono solo i primi 2 numeri
        { 
            if (array[0] == array[1])
            {
                printf("Primi 2 doppi\n");
                do//Genero altro numero diverso da quello precedentemente generato
                {
                    controllo = (rand() % (MAX - MIN)) + MIN;
                } while (controllo == result);
                array[i] == controllo;
            }
        }
        /*else if (i == 0)
        {
            printf("Primo\n");
        }*/
    }
}

void Controllo(int array[], int length)
{
    int doppioni = 0;
    for (int i = 0; i < length; i++)
    {
        if (i > 1)
        {
            for (int j = 0; j < (i - 1); j++)
            {
                if (array[j] == array[i])
                {
                    printf("Trovato doppione al posto %d e %d\n", j, i);
                    doppioni++;
                }
            }
        }
        
    }
    printf("I doppioni sono %d\n", doppioni);
}

void Ordinaarray(int array[],int length)
{
    for(int i=0;i<length;i++){

    }
}
int main()
{
    int array[100];
    int length = 100;
    Insertarray(array, length);
    for (int i = 0; i < length; i++)
    {
        printf("Il %d numero dell'array è %d\n", (i + 1), array[i]);
    }

    //Controllo(array,length);


    return 0;
}