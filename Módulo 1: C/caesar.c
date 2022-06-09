#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//call the verify function
bool verify(int argc, string argv[]);

//main function
int main(int argc, string argv[])
{
    bool allok = verify(argc, argv);

//aks the user for the input
    if (allok == true)
    {
        int key = atoi(argv[1]);
        string text = get_string("Plaintext: ");
        int length = strlen(text);
        printf("Ciphertext: ");

        for (int letter = 0; letter < length; letter++)
        {
            if (isalpha(text[letter]))
            {
                //change the uppercase letters
                if (isupper(text[letter]))
                {
                    int cipher_text = ((((int) text[letter] - 'A') + key) % 26);
                    printf("%c", cipher_text + 'A');
                }
                //change the lowercase letters
                else if (islower(text[letter]))
                {
                    int cipher_text = ((((int) text[letter] - 'a') + key) % 26);
                    printf("%c", cipher_text + 'a');
                }
            }
            //keep the spaces and the non alphabetic chars in the text
            else
            {
                printf("%c", text[letter]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//verify if the argmunent is valid
bool verify(int argc, string argv[])
{
    if (argv[2] != NULL)
    {
        return false;
    }
    if (isalpha(argv[1][1]))
    {
        return false;
    }
    else
    {
        return true;
    }
}
