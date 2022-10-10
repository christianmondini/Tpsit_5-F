#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<malloc.h>

int Scelta()
{
    int scelta=0;
    do{
        
        printf("Cosa vuoi fare?\n1)Inserisci numero\n2)Cerca numero\n3)Elimina numero\n4)Ordina array\n5)ESCI\n");
        scanf("%d",&scelta);
        if(scelta<1 || scelta>5)
            printf("Scelta non valida\n");
    }while(scelta<1 && scelta>5);
    return scelta;
}

void Inserisci(int array[],int *grandezza){
    int numero;
    printf("Inserisci il numero da aggiungere all'array\n");
    scanf("%d",&numero);
    (*grandezza)++;
    array=realloc(array, (*grandezza) *sizeof(int));
    array[(*grandezza)-1]=numero;
}

void PrintArray(int array[],int grandezza){
    for(int i=0;i<grandezza;i++){
        printf("%d) valore dell'array e' %d\n",(i+1),array[i]);
    }
}

int Reasearch(int array[],int grandezza){
    int search;
    int coincidenza=0;
    printf("Che numero vuoi cercare?\n");
    scanf("%d",&search);
    for(int i=0;i<grandezza;i++){
            if(array[i]==search){
                printf("Coincidenza trovata\n");
                coincidenza++;
                break;
            }
    }
    return coincidenza;
}

int ReasearchDelete(int array[],int grandezza,int delete){
    int coincidenza=0;
    for(int i=0;i<grandezza;i++){
            if(array[i]==delete){
                coincidenza++;
                break;
            }
    }
    return coincidenza;
}

void Elimina(int array[],int *grandezza){
int delete;
int counter=0;
do{
    
printf("Cosa vuoi eliminare?\n");
scanf("%d",&delete);
if(ReasearchDelete(array,*grandezza,delete)!=1)
    printf("Il numero che tenti di eliminare non e' nell'array\n");
else
    printf("Fatto\n");
}while(ReasearchDelete(array,*grandezza,delete)!=1);

for(int i = 0; i < ((*grandezza)- counter); i++){
        if(array[i] == delete){
            for(int j=i ;j < ((*grandezza)- counter -1); j++){
                array[j] = array[j+1];
            }
            counter++;
        }
    }
    (*grandezza) -= counter;
    array = realloc(array, (*grandezza) * sizeof(int));

}

void OrdinaArray(int array[],int grandezza){
    for(int i=0;i<grandezza;i++){
        for(int j=(i+1);j<grandezza;j++){
            if(array[i]>array[j]){
                int temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
}

int main(){
    int grandezza=0;
    int *array=malloc(grandezza *sizeof(int));
    int scelta;

    while(1){
        int num=0;
        int doppi=0;
        scelta=Scelta();
        

        switch(scelta){
            case 1:
                Inserisci(array,&grandezza);

                PrintArray(array,grandezza);
                break;
            case 2:
                doppi=Reasearch(array,grandezza);
                if(doppi==1)
                    printf("Numero trovato\n");
                else    
                    printf("Nessuna coincidenza\n");
                break;
            case 3:
                Elimina(array,&grandezza);

                PrintArray(array,grandezza);
                break;
            case 4:
                OrdinaArray(array,grandezza);

                PrintArray(array,grandezza);
                break;
            case 5:
                exit(0);
                break;
        }

    }

    free(array);
    return 0;
}