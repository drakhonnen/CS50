#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Pergunta o número do cartão
    long cnumber;
    do
    {
        cnumber = get_long("Qual o número do cartão? ");
    }
    while (cnumber < 0);

    //Desmembra os números do cartão - do último para o primeiro
    int a;
    a = cnumber % 10;

    int b;
    b = cnumber % 100 / 10 * 2;
    if (b >= 10)
    {
        b = b % 10 + b % 100 / 10;
    }

    int c;
    c = cnumber % 1000 / 100;

    int d;
    d = cnumber % 10000 / 1000 * 2;
    if (d >= 10)
    {
        d = d % 10 + d % 100 / 10;
    }

    int e;
    e = cnumber % 100000 / 10000;

    int f;
    f = cnumber % 1000000 / 100000 * 2;
    if (f >= 10)
    {
        f = f % 10 + f % 100 / 10;
    }

    int g;
    g = cnumber % 10000000 / 1000000;

    int h;
    h = cnumber % 100000000 / 10000000 * 2;
    if (h >= 10)
    {
        h = h % 10 + h % 100 / 10;
    }

    int i;
    i = cnumber % 1000000000 / 100000000;

    int j;
    j = cnumber % 10000000000 / 1000000000 * 2;
    if (j >= 10)
    {
        j = j % 10 + j % 100 / 10;
    }

    int k;
    k = cnumber % 100000000000 / 10000000000;

    int l;
    l = cnumber % 1000000000000 / 100000000000 * 2;
    if (l >= 10)
    {
        l = l % 10 + l % 100 / 10;
    }

    int m;
    m = cnumber % 10000000000000 / 1000000000000;

    int n;
    n = cnumber % 100000000000000 / 10000000000000 * 2;
    if (n >= 10)
    {
        n = n % 10 + n % 100 / 10;
    }

    int o;
    o = cnumber % 1000000000000000 / 100000000000000;

    int p;
    p = cnumber % 10000000000000000 / 1000000000000000 * 2;
    if (p >= 10)
    {
        p = p % 10 + p % 100 / 10;
    }

    //Soma os números
    int checksum;
    checksum = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p;

    //Seleciona os dois primeiros números
    long first2 = cnumber;
    do
    {
        first2 = first2 / 10;
    }
    while (first2 > 100);

    //Verifica o tipo de cartão
    if (cnumber > 999999999999 && checksum % 10 == 0)
    {
        if (first2 == 34 || first2 == 37)
        {
            printf("AMEX\n");
        }
        else if (first2 >= 40 && first2 <= 49)
        {
            printf("VISA\n");
        }
        else if (first2 >= 51 && first2 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
