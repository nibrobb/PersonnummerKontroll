#include <string_view>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>
#include <assert.h>

int check_personnummer(std::string &persnr)
{
    // int personnummer[11];
    std::vector<int> personnummer;
    personnummer.reserve(11);

    std::vector<int> sequence_1 = {3, 7, 6, 1, 8, 9, 4, 5, 2, 1};    /* Første spesielle tallrekke */
    std::vector<int> sequence_2 = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2, 1}; /* Andre spesielle tallrekke */

    std::cout << "Oppgitt fødselsnummer: ";

    for (auto &&x : persnr)
    {
        personnummer.push_back(x - '0');
        std::cout << x;
    }

    std::cout << "\n\n";

    std::vector<int> produkt_1;
    produkt_1.reserve(10);

    /* for (auto &&x : sequence_1)
    {
        produkt_1.push_back(personnummer.at(idx) * sequence_1.at(idx))
    } */

    for (size_t j = 0; j < sequence_1.size(); j++)
    {
        produkt_1.push_back(personnummer.at(j) * sequence_1.at(j));
    }

    auto sum_av_produkt_1 = std::reduce(produkt_1.begin(), produkt_1.end());

    /* Skriv ut det første produktet */
    std::cout << "Produkt_1 = ";

    unsigned i = 0;
    for (auto &&x : produkt_1)
    {
        std::cout << x << (i < produkt_1.size() - 1 ? ", " : "");
        ++i;
    }

    std::cout << "\nSum av produkt_1 = " << sum_av_produkt_1 << "\n\n";

    int rest_1 = sum_av_produkt_1 % 11;

    /* Forteller om første kontrollsiffer er gyldig*/
    const int kontrollsiffer_idx = 9;
    if (rest_1 == 0)
    {
        std::cout << "FØRSTE KONTROLLSIFFER (" << personnummer.at(kontrollsiffer_idx) << ") ER GYLDIG\n\n\n";
    }
    else
    {
        std::cout << "FØRSTE KONTROLLSIFFER (" << personnummer.at(kontrollsiffer_idx) << ") ER IKKE GYLDIG!\n\n\n";
    }

    std::vector<int> produkt_2;
    produkt_2.reserve(11);

    for (size_t l = 0; l < produkt_2.size(); l++)
    {
        produkt_2.push_back(personnummer.at(l) * sequence_2.at(l));
    }

    auto sum_av_produkt_2 = std::reduce(produkt_2.begin(), produkt_2.end());

    std::cout << "Produkt_2 = ";

    i = 0;
    for (auto &&x : produkt_2)
    {
        std::cout << x << (i < produkt_2.size() - 1 ? ", " : "");
        ++i;
    }

    std::cout << "\nSum an produkt_2 = " << sum_av_produkt_2 << "\n\n";

    int rest_2 = sum_av_produkt_2 % 11;

    if (rest_2 == 0)
    {
        std::cout << "ANDRE KONTROLLSIFFER (" << personnummer[10] << ") ER GYLDIG\n";
    }
    else
    {
        std::cout << "ANDRE KONTROLLSIFFER (" << personnummer[10] << ") ER IKKE GYLDIG!\n";
    }

    int status = 0; /* This is the status indicator, it will be 1 if the personnummer is valid, 0 otherwise*/

    if (rest_1 == 0 && rest_2 == 0)
    {
        status = 1;
        std::cout << "\n\nGYLDIG FØDSELSNUMMER\n";
    }
    else
    {
        std::cout << "\n\nUGLYDIG FØDSELSNUMMER\n";
    }

    return status;
}

inline void print_help(const char *name)
{
    std::cerr << "Usage: " << name << "[Personnummer]\n";
    std::cerr << "Options:\n\n";
    std::cerr << "\t--help\t\tShows this help screen" << std::endl;
}

/* Program for å sjekke kontrollsiffer i personnummer */
int main(int argc, char **argv)
{
    using namespace std::literals::string_view_literals;

    if (argc < 2)
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        if (argv[1] == "-h"sv || argv[1] == "--help"sv)
        {
            print_help(argv[0]);
            exit(EXIT_FAILURE);
        }

        std::string foo = argv[1];

        char *end;
        long num = strtol(argv[1], &end, 10);

        if (num != 0)
        {
            assert(foo.length() == 11);

            return check_personnummer(foo);
        } else {
            print_help(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
