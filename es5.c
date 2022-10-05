#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int array[2];
    int num;
    int accettabile;
    while (1)
    {
        printf("Inserisci un numero valido\n");
        if (scanf("%d", &num) == 1)
        {
            printf("OK\n");
            break;
        }
        else
            printf("Non e' intero\n");
    }

    printf("Il tuo numero è %d\n", num);
    return 0;
}