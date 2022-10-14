#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define DIM 100

//FINITO
int ControllaFrequenza(char stringa[],int dimensione,char carattere){
    int counter=0;
    for(int i=0;i<dimensione;i++){
        if(stringa[i]==carattere){
            counter++;
        }
    }

    return counter;

}

//FINITO
void ContaTipo(char stringa[],int dimensione,int *n_M,int *n_m,int *n_cs,int *n_num){
    for(int i=0;i<dimensione;i++){
        if(64<stringa[i] && stringa[i]<91){
            (*n_M)+=1;
        }else if(96<stringa[i] && stringa[i]<123){
            (*n_m)+=1;
        }else if(47<stringa[i]&& stringa[i]<58){
            (*n_num)+=1;
        }else if(0<=stringa[i] && stringa[i]<48 || 57<stringa[i] && stringa[i]<65 || 122<stringa[i] && stringa[i]<=127 ){
            (*n_cs)+=1;
        }

    }
}




//FINITO
void Ordina(char stringa[],int dimensione){
    for(int i=0;i<dimensione;i++){
        for(int j=i+1;j<dimensione;j++){
           if(stringa[i]>stringa[j]){
            char temp=stringa[i];
            stringa[i]=stringa[j];
            stringa[j]=temp;
           }
        }
    }

}

//FINITO
int ContaNonAlpha(char stringa[],int dimensione){
    int counter=0;
    for(int i=0;i<dimensione;i++){
        if(64<stringa[i] && stringa[i]<91 || 96<stringa[i] && stringa[i]<123){
        }else{
            counter++;
        }
        
    }

    return counter;
}

//FINITO
void Ordina2(char stringa[],int dimensione){
    for(int i=0;i<dimensione;i++){
        if(stringa[i]%2!=0){
            for(int j=i+1;j<dimensione;j++){
                if(stringa[j]%2!=0){
                    if(stringa[i]<stringa[j]){
                        char temp=stringa[i];
                        stringa[i]=stringa[j];
                        stringa[j]=temp;
                    }
                }
            }
        }
    }
}


int main(){
    char stringa[DIM];

    printf("Inserisci stringa:\n");
    scanf("%s",stringa);

    int carattere=0;

    int n_M=0;
    int n_m=0;
    int n_cs=0;
    int n_num=0;


    for(int i=0;i<strlen(stringa);i++){
        carattere=ControllaFrequenza(stringa,strlen(stringa),stringa[i]);
        printf("Il carattere %c compare %d volte nella stringa di peso ASCII %d\n",stringa[i],carattere,stringa[i]);

    }

    //ES 1 FINITO

    ContaTipo(stringa,strlen(stringa),&n_M,&n_m,&n_cs,&n_num);


    char maiuscole[n_M+1];
    char minuscole[n_m+1];
    char cs[n_cs+1];
    char num[n_num+1];

    printf("Maiuscole %d minuscole %d caratteri speciali %d numeri %d\n",n_M,n_m,n_cs,n_num);

    int counter=0;
    for(int i=0;i<strlen(stringa);i++){
        if(64<stringa[i] && stringa[i]<91){
            maiuscole[counter]=stringa[i];
            counter++;
        }
        if(counter==n_M){
                maiuscole[n_M]='\0';
        }
    }

    counter=0;

     for(int i=0;i<strlen(stringa);i++){
        if(96<stringa[i] && stringa[i]<123){
            minuscole[counter]=stringa[i];
            counter++;
        }
        if(counter==n_m){
                minuscole[n_m]='\0';
        }
    }

    counter=0;

     for(int i=0;i<strlen(stringa);i++){
        if(0<=stringa[i] && stringa[i]<48 || 57<stringa[i] && stringa[i]<65 || 122<stringa[i] && stringa[i]<=127){
            cs[counter]=stringa[i];
            counter++;
        }
        if(counter==n_cs){
                cs[n_cs]='\0';
        }
    }

    counter=0;

    for(int i=0;i<strlen(stringa);i++){
        if(47<stringa[i]&& stringa[i]<58){
            num[counter]=stringa[i];
            counter++;
        }
        if(counter==n_num){
                num[n_num]='\0';
        }
    }

    Ordina(maiuscole,n_M);
    Ordina(minuscole,n_m);
    Ordina(cs,n_cs);
    Ordina(num,n_num);

    printf("%s\n",maiuscole);
    printf("%s\n",minuscole);
    printf("%s\n",cs);
    printf("%s\n",num);

    int grandezza=n_num+n_M+n_m+n_cs;
    char stampa[grandezza+1];


   counter=0;

   for(int i=0;i<n_M;i++){
        stampa[i]=maiuscole[counter];
        counter++;
   }

   counter=0;

   for(int i=n_M;i<(n_M+n_m);i++){
        stampa[i]=minuscole[counter];
        counter++;
   }

   counter=0;

   for(int i=(n_M+n_m);i<(n_M+n_m+n_cs);i++){
        stampa[i]=cs[counter];
        counter++;
   }

   counter=0;

   for(int i=(n_M+n_m+n_cs);i<grandezza;i++){
        stampa[i]=num[counter];
        counter++;
   }

    stampa[grandezza]='\0';

    printf("%s\n",stampa);
    //ES 2 FINITO

    int finale=ContaNonAlpha(stampa,grandezza);
    printf("%d",finale);
    char stringaf[finale+1];

    counter=0;

    for(int i=0;i<grandezza;i++){
        if(64<stampa[i] && stampa[i]<91 || 96<stampa[i] && stampa[i]<123){

        }else{
        stringaf[counter]=stampa[i];
        counter++;
        }
    }

    stringaf[finale]='\0';

    Ordina2(stringaf,finale);
    printf("%s",stringaf);


    return 0;
}