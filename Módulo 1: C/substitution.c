#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool validate(int argc, string argv[]); //call the validate function

int main(int argc, string argv[]) //main function that cipher the text
{
    bool allok = validate(argc, argv);

    if (allok == true) //verify if the input was valid
    {
        string plaintext = get_string("Plaintext: "); //get the plaintext
        string key = argv[1];
        printf("\n");
        printf("ciphertext: ");
        for (int i = 0; i <strlen(key); i++)
        {
            if (islower(key[i]))
            {
                key[i] = key[i] - 32;
            }
        }

        for (int x = 0, y = strlen(plaintext); x < y; x++) //encrypt the text
        {
            if (islower(plaintext[x]))
            {
                int letter = plaintext[x] - 97;
                printf("%c", key[letter] + 32);
            }
            else if (isupper(plaintext[x]))
            {
                int letter = plaintext[x] - 65;
                printf("%c", key[letter]);
            }
            else
            {
                printf("%c", plaintext[x]);
            }
        }
        printf("\n");
    }
    else
    {
        return 1;
    }
    printf("\n");
}

bool validate(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substituition KEY\n");
        return false;
        return 1;
    }
    for (int l = 0, length = strlen(argv[1]); l < length; l++)
    {
        if (isdigit(argv[1][l])) //search for numbers
        {
            printf("Key must only contain alphabetic characters. \n");
            return false;
            return 1;
        }
        for (int x = l + 1; x < length; x++) //search repeated characters
        {
            if (argv[1][l] - '0' == argv[1][x] - '0')
            {
                printf("Key must not contain repeated characters\n");
                return false;
                return 1;
            }
        }
    }
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26) //verify the length
    {
        printf("The Key must contain 26 characters\n");
        return false;
        return 1;
    }
    else
    {
        return true;
        return 0;
    }
}
