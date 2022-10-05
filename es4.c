#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONTROLLA VALIDITA' DELLA PAROLA
void Validaparola(char *parola)
{
    int accettabile;
    do
    {
        accettabile = 0;
        printf("Inserisci una parola\n");
        scanf("%s", parola);
        printf("La parola e' %s\n", parola);
        for (int i = 0; i < strlen(parola); i++)
        {
            if ((parola[i] > 64 && parola[i] < 91) || (parola[i] > 96 && parola[i] < 123))
            {
                accettabile++;
                // printf("accettabile\n");
            }
            else
            {
                printf("Trovato valore non valido della stringa alla lettera %d della parola, dovrai scrivere un'altra parola\n", (i + 1));
            }
        }
    } while (accettabile != strlen(parola));
}

void Scelta(int *scelta)
{
    int valido;
    do
    {
        valido = 0;
        printf("Inserisci scelta\n");
        scanf("%d", scelta);
        if (*scelta != 1 && *scelta != 2 && *scelta != 3 && *scelta != 4 && *scelta != 5 && *scelta != 6)
        {
            printf("Scelta non valida\n");
        }
        else
        {
            // printf("Valore valido\n");
            valido = 1;
        }
    } while (valido != 1);
}
// CONTROLLA QUANTITA' VOCALI CONTENUTE
int Vocali(char *parola)
{
    int vocali = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] == 65 || parola[i] == 97 || parola[i] == 69 || parola[i] == 101 || parola[i] == 73 || parola[i] == 105 || parola[i] == 79 || parola[i] == 111 || parola[i] == 85 || parola[i] == 117)
        {
            vocali++;
        }
    }
    return vocali;
}

// CONTROLLA QUANTITA' CONSONANTI CONTENUTE
int Consonanti(char *parola)
{
    int consonanti = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] != 65 && parola[i] != 97 && parola[i] != 69 && parola[i] != 101 && parola[i] != 73 && parola[i] != 105 && parola[i] != 79 && parola[i] != 111 && parola[i] != 85 && parola[i] != 117)
        {
            consonanti++;
        }
    }
    return consonanti;
}

// TROVA LETTERE CERCATE DA UTENTE
int Trovalettera(char *parola, char lettera)
{
    int risposta = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] == lettera)
            risposta++;
    }
    return risposta;
}

// LETTERE PARI
void Pari(char *parola, char *pari)
{
    int j = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (i % 2 != 0)
        { // Prendo i dispari perche' la parola parte da 1 e nn da 0
            pari[j] = parola[i];
            j++;
            //printf("CARATTERE PARI %c\n", parola[i]);
        }
    }
}

// LETTERE DISPARI
void Dispari(char *parola, char *dispari)
{
    int j = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (i % 2 == 0)
        { // Prendo i pari perche' la parola parte da 1 e non da 0
            dispari[j] = parola[i];
            j++;
            //printf("CARATTERE DISPARI %c\n", parola[i]);
        }
    }
}

// RICERCA DOPPIE
int Doppie(char *parola)
{
    int doppie = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        for (int j = (i + 1); j < strlen(parola); j++)
        {
            if (parola[i] == parola[j])
            {
                doppie++;
            }
        }
    }
    return doppie;
}

// MAIN
int main(int argc, char *argv[])
{
    char parola[100];
    Validaparola(parola);
    int lunghezza = strlen(parola);
    // printf("%d",lunghezza);
    int lunga1;
    int lunga2;
    if ((lunghezza % 2) == 0)
    { // Se parola lunghezza pari: le lettere pari e dispari saranno uguali
        lunga1 = (lunghezza / 2);
        lunga2 = (lunghezza / 2);
    }
    else
    { // invece se lunghezza parola dispari
        lunghezza += 1;
        // printf(" LUNGHEZZA +1 %d\n",lunghezza);
        lunga1 = (lunghezza / 2) - 1;
        lunga2 = (lunghezza / 2);
    }

    /* printf("LUNGA1 %d",lunga1);
     printf("LUNGA2 %d",lunga2);*/
    // setto le stringhe per i caratteri pari o dispari di lunghezza giusta
    char stringap[lunga1 + 1];
    char stringad[lunga2 + 1];

    stringap[lunga1] = '\0';
    stringad[lunga2] = '\0';

    do
    {

        printf("Scegli cosa vuoi fare\n1)Se vuoi vedere numero vocali\n2)Se vuoi vedere numero consonanti\n3)Se vuoi cercare una lettera nella parola\n4)Se vuoi dividere le lettere nelle posizioni pari da quelle dispari\n5)Per vedere il numero di doppie\n6)Se vuoi uscire\n");
        int scelta;
        Scelta(&scelta);
        int vocali = 0;
        int consonanti = 0;
        int ricerca = 0;
        int doppie = 0;

        switch (scelta)
        {
        case 1:
            vocali = Vocali(parola);
            printf("Le vocali sono %d\n", vocali);
            break;
        case 2:
            consonanti = Consonanti(parola);
            printf("Le consonanti sono %d\n", consonanti);

            break;
        case 3:

            printf("Inserisci una lettera da ricercare all'interno della parola\n");
            char c;
            scanf(" %c", &c); // Spazio obbligatorio prima di carattere
            ricerca = Trovalettera(parola, c);
            if (ricerca > 0)
            {
                printf("Sono state trovate %d ricorrenze\n", ricerca);
            }
            else
            {
                printf("Nessuna riccorrenza trovata\n");
            }
            break;
        case 4:

            Pari(parola, stringap);
            Dispari(parola, stringad);

            printf("Le lettere pari sono:\n");
            for (int i = 0; i < strlen(stringap); i++)
            {
                printf(" %c\n", stringap[i]);
            }

            printf("Mentre quelle dispari sono:\n");
            for (int i = 0; i < strlen(stringad); i++)
            {
                printf(" %c\n", stringad[i]);
            }
            break;
        case 5:
            doppie = Doppie(parola);
            if (doppie > 0)
            {
                printf("Le doppie sono %d\n", doppie);
            }
            else
            {
                printf("Non ci sono doppie\n");
            }
            break;
        case 6:
            exit(0);
            break;
        }
    } while (1);

    return 0;
}