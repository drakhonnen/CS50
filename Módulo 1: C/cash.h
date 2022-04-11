#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //pergunta o troco
    float change;
    do
    {
        change = get_float("Qual o troco? ");
    }
    while (change <= 0);

    //converte os centavos
    int q = round(change * 100);

    //cria o contador de moedas
    int moedas = 0;

    //calcula quantidade de quarters
    while (q >= 25)
    {
        q = q - 25;
        moedas++;
    }

    //calcula a quantidade de dimes
    while (q >= 10)
    {
        q = q - 10;
        moedas++;
    }

    //calcula a quantidade de nickels
    while (q >= 5)
    {
        q = q - 5;
        moedas++;
    }

    //calcula a quantidade de pennys
    while (q >= 1)
    {
        q = q - 1;
        moedas++;
    }
    printf("%i\n", moedas);
}
