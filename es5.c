#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void Scelta(int *scelta){
   do{
    printf("\nInserisci la tua scelta:\n");
    scanf("%d", scelta);
    if(*scelta<1 || *scelta>6){

        printf("Scelta non valida\n");
    }
    else{
        printf("Scelta fatta\n");
    }
    }while(*scelta<1 || *scelta>6);
}

void Addsize(int *size){
*size++;
}

void ArrayInsert(int array[],int num,int size){
    
    array[size-1]=num;
}



int main(){
    int size=0;
    int array[size];
    int n;
    int scelta;

    
    while(1){
        printf("Premi\n1)Per inserire un valore nell'array\n2)Per\n3)Per\n4)Per\n5)Per uscire\n");
        Scelta(&scelta);
        n=0;
        //printf("%d",n);
        switch(scelta){
            case 1:
                    printf("Scegli il numero che vuoi inserire nell'array:\n");
                    scanf("%d",&n);
                    Addsize(&size);
                    ArrayInsert(array,n,size);
                    printf("%d",array[0]);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                exit(0);
                break;

        }
    }

    return 0;
}
