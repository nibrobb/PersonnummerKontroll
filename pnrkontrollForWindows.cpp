#include <iostream>
#include <stdlib.h>     /* atoi */
#include <string.h>     /* strlen */
#include <string>
#include <Windows.h>

#pragma comment(lib, "user32.lib")


int check_personnummer(char* persnr)
{
    int personnummer[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    const int tallrekke_1[10] = { 3, 7, 6, 1, 8, 9, 4, 5, 2, 1 };     /* Første spesielle tallrekke */
    const int tallrekke_2[11] = { 5, 4, 3, 2, 7, 6, 5, 4, 3, 2, 1 };  /* Andre spesielle tallrekke */



    std::string oppgifnr("Oppgitt fødselsnummer: ");
    ::CharToOemA(oppgifnr.c_str(), const_cast<char*>(oppgifnr.c_str()));
    std::cout << oppgifnr;

    for (size_t i = 0; i < strlen(persnr); i++)
    {
        personnummer[i] = persnr[i] - '0';      /* ASCII-tricery for å parse en enkelt int*/
        printf("%i", personnummer[i]);
    }

    printf("\n\n\n\n");

    int produkt_1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int sum_av_produkt_1 = 0;

    for (int j = 0; j < 10; j++)
    {
        produkt_1[j] = personnummer[j] * tallrekke_1[j];
        sum_av_produkt_1 += produkt_1[j];
    }


    /* Just print the first product */
    printf("Produkt_1 = ");

    for (int k = 0; k < 10; k++) {
        printf("%i", produkt_1[k]);
        if (k < 9)
            printf(", ");
    }
    printf("\n");

    printf("Sum av produkt_1 = %i\n\n", sum_av_produkt_1);

    int rest_1 = sum_av_produkt_1 % 11;

    std::string first_control("FØRSTE KONTROLLSIFFER (");
    ::CharToOemA(first_control.c_str(), const_cast<char*>(first_control.c_str()));

    /* Forteller om første kontrollsiffer er gyldig*/
    if (rest_1 == 0) {
        std::cout << first_control << personnummer[9] << ") ER GYLDIG\n\n\n";
        //printf("FØRSTE KONTROLLSIFFER (%i) ER GYLDIG\n\n\n", personnummer[9]);
    }
    else {
        std::cout << first_control << personnummer[9] << ") ER IKKE GYLDIG\n\n\n";
        //printf("FØRSTE KONTROLLSIFFER (%i) ER IKKE GYLDIG!\n\n\n", personnummer[9]);
    }



    int produkt_2[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int sum_av_produkt_2 = 0;

    for (int l = 0; l < 11; l++)
    {
        produkt_2[l] = personnummer[l] * tallrekke_2[l];
        sum_av_produkt_2 += produkt_2[l];
    }

    printf("Produkt_2 = ");
    for (int m = 0; m < 11; m++) {
        printf("%i", produkt_2[m]);
        if (m < 10)
            printf(", ");
    }
    printf("\n");

    printf("Sum an produkt_2 = %i\n\n", sum_av_produkt_2);

    int rest_2 = sum_av_produkt_2 % 11;


    if (rest_2 == 0) {
        printf("ANDRE KONTROLLSIFFER (%i) ER GYLDIG\n", personnummer[10]);
    }
    else {
        printf("ANDRE KONTROLLSIFFER (%i) ER IKKE GYLDIG!\n", personnummer[10]);
    }

    int status = 0; /* This is the status indicator, it will be 1 if the personnummer is valid, 0 otherwise*/


    std::string gyldig("GYLDIG FØDSELSNUMMER");
    ::CharToOemA(gyldig.c_str(), const_cast<char*>(gyldig.c_str()));


    if (rest_1 == 0 && rest_2 == 0) {
        status = 1;
        std::cout << "\n\n" << gyldig << std::endl;
    }
    else {
        std::cout << "\n\nU" << gyldig << std::endl;
        //printf("\n\nUGLYDIG FØDSELSNUMMER\n");
    }

    return status;
}


/* Program for å sjekke kontrollsiffer i personnummer */
int main(int argc, char** argv)
{
    char buffer[11];

    //printf("Vennligst oppgi ditt fødselsnummer (11 siffer): ");
    std::string oppgi("Vennligst oppgi ditt fødselsnummer: ");
    ::CharToOemA(oppgi.c_str(), const_cast<char*>(oppgi.c_str()) );

    std::cout << oppgi;
    std::cin >> buffer;
    std::cout << std::endl;



    int checked_number = check_personnummer(buffer);

    if (checked_number)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

}