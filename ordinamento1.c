#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define DIM 100


int Controllanumero(int array[],int dimensione,int numero){
    int doppione=0;
    for(int i=0;i<dimensione;i++){
        if(array[i]==numero){
            doppione++;
            break;
        }
    }
    return doppione;
}

void GeneraArray(int array[],int dimensione){
    int num=0;
    for(int i=0;i<dimensione;i++){
        num= 1 + rand() % 232;
        if(Controllanumero(array,i,num)==0 || i==0){
            array[i]=num;
        }else{
            i--;
        }
    }
}


void PrintArray(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
        printf("[%d] %d\n",i,array[i]);
    }

}

void Ordina(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
        for(int j=i+1;j<dimensione;j++){
            if(array[i]>array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void OrdinaContrario(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
        for(int j=i+1;j<dimensione;j++){
            if(array[i]<array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void PariDispari(int array[],int dimensione,int pari[],int dispari[],int *n_pari,int *n_dispari){

    for(int i = 0; i < dimensione; i++){
        if(array[i] % 2 == 0 && *n_pari<20){
            pari[*n_pari]=array[i];
            (*n_pari)++;
        }
        
        if(array[dimensione-i-1] % 2 != 0 && *n_dispari<20)
        {
            dispari[*n_dispari]=array[dimensione-i-1];
            (*n_dispari)++;
        }
    }
}



int main(){
    srand(time(NULL));
    int array[DIM];
    GeneraArray(array,DIM);
    Ordina(array,DIM);
    PrintArray(array,DIM);

    int pari[20];
    int dispari[20];
    int n_pari=0;
    int n_dispari=0;

    PariDispari(array,DIM,pari,dispari,&n_pari,&n_dispari);

   /* printf("Array pari:\n");
    PrintArray(pari,n_pari);*/
    printf("Array dispari:\n");
    PrintArray(dispari,n_dispari);

    int restanti[80];
    int n_restanti=0;

    for(int i=0;i<DIM;i++){
        if(array[i] % 2 == 0 && Controllanumero(pari,n_pari,array[i])==0){
            restanti[n_restanti]=array[i];
            n_restanti++;
        }else if(array[i] % 2 != 0 && Controllanumero(dispari,n_dispari,array[i])==0)
        {
            restanti[n_restanti]=array[i];
            n_restanti++;
        }
    }

    int stamp[DIM];
    int pos=0;

    for(int i=0; i<n_pari;i++){
        stamp[pos]=pari[i];
        pos++;
    }

    for(int i=0; i<n_dispari;i++){
        stamp[pos]=dispari[i];
        pos++;
    }

    for(int i=0; i<n_restanti;i++){
        stamp[pos]=restanti[i];
        pos++;
    }

    printf("Finale:\n");
    PrintArray(stamp,DIM);


    return 0;
}