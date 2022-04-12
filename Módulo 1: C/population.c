#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Pergunta a população inicial
    int ipopulation;
    int fpopulation;

    do
    {
        ipopulation = get_int("Qual a população inicial? ");
    }
    while (ipopulation < 9);

    //Pergunta a população final
    do
    {
        fpopulation = get_int("Qual a população final? ");
    }
    while (fpopulation < ipopulation);

    //Calcula os anos necessários
    int years;

    for (years = 0; ipopulation < fpopulation; years++)
    {
        ipopulation = ipopulation + round((ipopulation / 3)) - round((ipopulation / 4));
    }
    printf("Years: %i\n", years);
}
