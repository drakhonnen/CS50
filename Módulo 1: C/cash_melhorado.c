#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //pergunta o valor
    float total;
    do
    {
        total = get_float("Qual é o valor total do(s) produtos? ");
    }
    while (total < 0);

    float r;
    do
    {
        r = get_float("Qual o valor recebido? ");
    }
    while (r < total);

    float change = (r - total);
    
    printf(" \n");
    printf("Troco do cliente: %g\n", change);

    //converte os centavos
    int q = round(change * 100);

    //cria o contador de moedas
    int notas = 0;
    int moedas = 0;
    int lobo = 0;
    int peixe = 0;
    int onça = 0;
    int mico = 0;
    int arara = 0;
    int garça = 0;
    int tartaruga = 0;
    int real = 0;
    int barão = 0;
    int deodoro = 0;
    int pedro1 = 0;
    int tiradentes = 0;

    //calcula a quantidade de lobo
    while (q >= 20000)
    {
        q = q - 20000;
        notas++;
        lobo++;
    }

    //calcula a quantidade de peixe
    while (q >= 10000)
    {
        q = q - 10000;
        notas++;
        peixe++;
    }

    //calcula a quantidade de onça
    while (q >= 5000)
    {
        q = q - 5000;
        notas++;
        onça++;
    }

    //calcula a quantidade de mico
    while (q >= 2000)
    {
        q = q - 2000;
        notas++;
        mico++;
    }

    //calcula a quantidade de arara
    while (q >= 1000)
    {
        q = q - 1000;
        notas++;
        arara++;
    }

    //calcula a quantidade de garça
    while (q >= 500)
    {
        q = q - 500;
        notas++;
        garça++;
    }

    //calcula a quantidade de tartaruga
    while (q >= 200)
    {
        q = q - 200;
        notas++;
        tartaruga++;
    }

    //calcula a quantidade de 1 real
    while (q >= 100)
    {
        q = q - 100;
        moedas++;
        real++;
    }

    //calcula a quantidade de baroes
    while (q >= 48)
    {
        q = q - 50;
        moedas++;
        barão++;
    }

    //calcula quantidade de deodoros
    while (q >= 24)
    {
        q = q - 25;
        moedas++;
        deodoro++;
    }

    //calcula a quantidade de pedro1s
    while (q >= 8)
    {
        q = q - 10;
        moedas++;
        pedro1++;
    }

    //calcula a quantidade de tiradentes
    while (q >= 4)
    {
        q = q - 5;
        moedas++;
        tiradentes++;
    }

    if (notas > 0)
    {
        printf("QUANTIDADE TOTAL DE CÉDULAS DEVIDAS: %i\n", notas);
    }

    if (moedas > 0)
    {
        printf("QUATIDADE TOTAL DE MOEDAS DEVIDAS: %i\n", moedas);
    }

    if (lobo > 0)
    {
        printf("Cédulas de 200 reais devidas: %i\n", lobo);
    }

    if (peixe > 0)
    {
        printf("Cédulas de 100 reais devidas: %i\n", peixe);
    }

    if (onça > 0)
    {
        printf("Cédulas de 50 reais devidas: %i\n", onça);
    }

    if (mico > 0)
    {
        printf("Cédulas de 20 reais devidas: %i\n", mico);
    }

    if (arara > 0)
    {
        printf("Cédulas de 10 reais devidas: %i\n", arara);
    }

    if (garça > 0)
    {
        printf("Cédulas de 5 reais devidas: %i\n", garça);
    }

    if (tartaruga > 0)
    {
        printf("Cédulas de 2 reais devidas: %i\n", tartaruga);
    }

    if (real > 0)
    {
        printf("Moedas de 1 real devidas: %i\n", real);
    }

    if (barão > 0)
    {
        printf("Moedas de 50 centavos devidas: %i\n", barão);
    }

    if (deodoro > 0)
    {
        printf("Moedas de 25 centavos devidas: %i\n", deodoro);
    }

    if (pedro1 > 0)
    {
        printf("Moedas de 10 centavos devidas: %i\n", pedro1);
    }

    if (tiradentes > 0)
    {
        printf("Moedas de 5 centavos devidas: %i\n", tiradentes);
    }
}
