#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long P1; long P2;
    do
    {
        P1 = get_long("Qual a nota da primeira prova? ");
    }
    while (P1 < 0);

    do
    {
        P2 = get_long("Qual a nota da segunda prova? ");
    }
    while (P2 < 0);

    long m;
    m = ((P1 + (2*P2)) / 3);

    printf("A média é: %li\n", m);

    if (m < 6)
    {
        printf("Reprovado\n");
    }
    if (m >= 6)
    {
         printf("Aprovado\n");
    }
}
