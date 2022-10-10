#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM 100

void CreaArray(int array[],int dimensione,int *pari,int *dispari){
    int num;
    for(int i=0;i<dimensione;i++){
        num= 1 + rand() % 233;
        for(int j=0;j<=i;j++){
            if(array[j]==num){
                i--;
                break;
            }
            if(j==i){
                 if(num%2==0){
                        (*pari)++;
                   }else
                    {
                        (*dispari)++;
                    }
                
            array[i]=num;
            }

           
        }

    }
}

void PrintArray(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
        printf("%d) %d\n",(i+1),array[i]);
    }
}

void Ordina(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
          for(int j=0;j<dimensione;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
          }
    }
}

void OrdinaContrario(int array[],int dimensione){
     for(int i=0;i<dimensione;i++){
          for(int j=0;j<dimensione;j++){
            if(array[j]<array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
          }
    }
}

/*void Ordina1(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
            if(array[i]>array[i+1]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                i=-1;
            }
    }
}*/

void Controllo(int array[],int dimensione){
    for(int i=0;i<dimensione;i++){
        for(int j=(i+1);j<dimensione;j++){
           if(array[i]==array[j]){
                printf("Trovato dopione al posto %d e %d\n",(i+1),(j+1));
            }
        }
       
    }
}

void PariDispari(int array[],int pari [],int dispari[],int dimensione,int *p,int *d){
    for(int i=0;i<dimensione;i++){
        if(array[i]%2==0){
            pari[*p]=array[i];
            (*p)++;
        }else{
            dispari[*d]=array[i];
            (*d)++;
        }
    }

    Ordina(pari,*p);
    OrdinaContrario(dispari,*d);
}

void Ordinafinale(int array[],int inizio,int dimensione){
    for(int i=inizio;i<dimensione;i++){
        for(int j=inizio;j<dimensione;j++){
            if(array[j]>array[j+1]){

                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }

        }
    }

}

int main()
{
    srand(time(NULL));
    int array[DIM],contapari=0,contadispari=0,d=0,p=0,k=0;
    CreaArray(array,DIM,&contapari,&contadispari);
    Ordina(array,DIM);
    //PrintArray(array,DIM);
    //Controllo(array,DIM);
   /*printf("%d ECCOMI",contapari);
    
    printf("%d ECCOMI",contadispari);*/
    int pari[contapari];
    int dispari[contadispari];

    if(contapari>20){
        contapari=20;
    }

     if(contadispari>20){
        contadispari=20;
    }

    PariDispari(array,pari,dispari,DIM,&p,&d);
   /* PrintArray(pari,p);
    PrintArray(dispari,d);*/

    for(int i=contapari;i<p;i++){
        array[contapari+contadispari+k]=pari[i];
        k++;
    }

     for(int i=contadispari;i<d;i++){
        array[contapari+contadispari+k]=dispari[i];
        k++;
    }

      for (int i = 0; i < contapari; i++)
    {
        array[i] = pari[i];
    }

    for (int i = 0; i < contadispari; i++)
    {
        array[contapari+i] = dispari[i];
    }
    int inizio=contapari+contadispari;
    Ordinafinale(array,inizio,DIM);
    PrintArray(array,DIM);
    Controllo(array,DIM);
    return 0;
}