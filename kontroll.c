#include <stdio.h>      /* printf */
#include <stdlib.h>     /* atoi */
#include <string.h>     /* strlen */


int check_personnummer(const char* persnr)
{
    int personnummer[11];

    const int const tallrekke_1[10] = {3, 7, 6, 1, 8, 9, 4, 5, 2, 1};     /* Første spesielle tallrekke */
    const int const tallrekke_2[11] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2, 1};  /* Andre spesielle tallrekke */

    

    printf("Oppgitt fødselsnummer: ");
    for (int i = 0; i < strlen(persnr); i++)
    {
        personnummer[i] = persnr[i] - '0';      /* ASCII-tricery for å parse en enkelt int*/
        printf("%i", personnummer[i]);
    }

    printf("\n\n");

    int produkt_1[10];
    int sum_av_produkt_1;

    for (int j = 0; j < 10; j++)
    {
        produkt_1[j] = personnummer[j] * tallrekke_1[j];
        sum_av_produkt_1 += produkt_1[j];
    }


    /* Just print the first product */
    printf("Produkt_1 = ");
    
    for (int k = 0; k < 10; k++) {
        printf("%i", produkt_1[k]);
        if(k < 9)
            printf(", ");
    }
    printf("\n");

    printf("Sum av produkt_1 = %i\n\n", sum_av_produkt_1);

    int rest_1 = sum_av_produkt_1 % 11;

    /* Forteller om første kontrollsiffer er gyldig*/
    if (rest_1 == 0) {
        printf("FØRSTE KONTROLLSIFFER (%i) ER GYLDIG\n\n\n", personnummer[9]);
    } else {
        printf("FØRSTE KONTROLLSIFFER (%i) ER IKKE GYLDIG!\n\n\n", personnummer[9]);
    }



    int produkt_2[11];
    int sum_av_produkt_2;

    for (int l = 0; l < 11; l++)
    {
        produkt_2[l] = personnummer[l] * tallrekke_2[l];
        sum_av_produkt_2 += produkt_2[l];
    }

    printf("Produkt_2 = ");
    for (int m = 0; m < 11; m++) {
        printf("%i", produkt_2[m]);
        if(m < 10)
            printf(", ");
    }
    printf("\n");

    printf("Sum an produkt_2 = %i\n\n", sum_av_produkt_2);

    int rest_2 = sum_av_produkt_2 % 11;


    if (rest_2 == 0) {
        printf("ANDRE KONTROLLSIFFER (%i) ER GYLDIG\n", personnummer[10]);
    } else {
        printf("ANDRE KONTROLLSIFFER (%i) ER IKKE GYLDIG!\n", personnummer[10]);
    }

    int status = 0; /* This is the status indicator, it will be 1 if the personnummer is valid, 0 otherwise*/

    if (rest_1 == 0 && rest_2 == 0) {
        status = 1;
        printf("\n\nGYLDIG FØDSELSNUMMER\n");
    } else {
        printf("\n\nUGLYDIG FØDSELSNUMMER\n");
    }

    return status;
}


/* Program for å sjekke kontrollsiffer i personnummer */
int main(int argc, char **argv)
{
    /*
    TODO:
        add -v (verbose) flag, for step-by-step printing
    */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [Personnummer], for help use --help\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "Usage: %s [Personnummer]\n", argv[0]);
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "   --help\t\tShows this help screen\n");
        exit(EXIT_FAILURE);
    }


    int checked_number = check_personnummer(argv[1]);

    if (checked_number)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);
        
}

