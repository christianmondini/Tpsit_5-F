#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 233
#define MIN 1

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min)) // genera numeri random in un certo range di valori

void Insertarray(int array[], int length)
{
    int controllo = 0;
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result = randnum(MIN, MAX);
        array[i] = result;
        if (i > 1) // Se sono almeno 2 numeri
        {
            for (int j = 0; j < (i - 1); j++) // controllo che non ci siano doppioni ed in caso genero un altro numero dicerso da tutti gli altri
            {
                if (array[j] == array[i])
                {
                    // printf("Generazione");
                    controllo = randnum(MIN, MAX);
                    array[i] = controllo;
                    j = 0;
                }
            }
        }
        else if (i == 1) // Se sono solo i primi 2 numeri
        {
            if (array[0] == array[1])
            {
                printf("Primi 2 doppi\n");
                do // Genero altro numero diverso da quello precedentemente generato
                {
                    controllo = randnum(MIN, MAX);
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

void OrdinaArray(int array[], int length)
{
    int temp;
    for (int i = 0; i < (length - 1);)
    {

        if (array[i] > array[i + 1])
        {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = 0;
        }
        else
        {
            i++;
        }
    }
}

void OrdinaArrayContrario(int array[],int length){
     int temp;
    for (int i = 0; i < (length - 1);)
    {

        if (array[i] < array[i + 1])
        {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = 0;
        }
        else
        {
            i++;
        }
    }
}

int Pari(int array[], int pari[])
{
    int counterpari = 0;
    for (int i = 0; i < 40; i++)
    {
        if (array[i] % 2 == 0 && counterpari < 20)
        {
            // printf("pari trovato alla posizione %d\n", i);
            pari[counterpari] = array[i];
            counterpari++;
        }
    }
    return counterpari;
}

int Dispari(int array[], int dispari[])
{
    int counterd = 0;
    for (int i = 0; i < 40; i++)
    {
        if (array[i] % 2 != 0 && counterd < 20)
        {
            // printf("pari trovato alla posizione %d\n", i);
            dispari[counterd] = array[i];
            counterd++;
        }
    }
    return counterd;
}

void PrintArray(int array[],int length,char nome[]){
    for (int i = 0; i < length; i++)
    {
        printf("Ecco l'array %s [%d]: %d\n",nome, i, array[i]);
    }
    printf("\n");
}

void RifaiArray(int sorgente[],int destinazione[],int length,int partenza){
    for(int i=0;i<length;i++){
        destinazione[i+partenza]=sorgente[i];
    }

}

int main()
{
    srand(time(NULL));
    int array[100];
    char arraynome[]="normale";
    int length = 100;
    Insertarray(array, length);
   
    OrdinaArray(array, length);
    PrintArray(array,length,arraynome);

    int pari[20];
    int dispari[20];
    char parinome[]="di pari";
    char disparinome[]="di dispari";

    int counterpari = Pari(array, pari);
    int counterd = Dispari(array, dispari);

    PrintArray(pari,counterpari,parinome);
    OrdinaArrayContrario(dispari,counterd);
    PrintArray(dispari,counterd,disparinome);

    RifaiArray(pari,array,counterpari,0);
    RifaiArray(dispari,array,counterd,20);

    PrintArray(array,length,arraynome);
    Controllo(array,length);
    return 0;
}