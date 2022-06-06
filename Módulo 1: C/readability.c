#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

void readlvl(string);
void coleman(float, float);

int main(void)
{
    //asks the text to the user
    string text = get_string("Text?\n");
    readlvl(text);
}

void readlvl(string text)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int x = 0, length = strlen(text); x < length; x++)
    {
        //verify if the char is a letter and count the letters
        if (isalnum(text[x]))
        {
            letters++;
        }
        //verify if the char is a empty space and count the space
        if (isspace(text[x]))
        {
            words++;
        }
        //verify if the char is a ponctuation and count the sentences
        if (text[x] == '.' || text[x] == '?' || text[x] == '!')
        {
            sentences++;
        }
    }

//calculate the variables for the formula
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    coleman(L, S);

}

void coleman(float L, float S)
{
    //Coleman-Liau index
    int formula = round(((0.0588 * L) - (0.296 * S) - 15.8));

    //Print the grade in the user's screen
    if (formula >= 1 && formula <= 16)
    {
        printf("Grade %i\n", formula);
    }
    else if (formula < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (formula > 16)
    {
        printf("Grade 16+\n");
    }
}
