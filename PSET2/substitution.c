#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Prototype
int test_arguments(int arguments, string key[]);
int encipher(string plaintext, string key);

//Setting the args
int main(int argc, string argv[])
{
    //testing the arguments
    if (test_arguments(argc, argv))
    {
        return 1;
    }
    else
    {
        //Encipher the plaintext
        string key = argv[1];
        string text = get_string("Enter a plaintext: ");
        // encipher the text and key;
        return encipher(text, key);
    }

}


int test_arguments(int arguments, string key[])
{
    //adding conditions
    if (arguments != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    else if (strlen(key[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, n = strlen(key[1]); i < n; i++)
    {
        char i_char = key[1][i];
        if (!isalpha(i_char))
        {
            //asking for alphabetic chars only
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        for (int j = 0; j < n; j++)
        {
            char j_char = key[1][j];
            if (toupper(i_char) == toupper(j_char) && i != j)
            {
                //No repeated chars
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

//enciphering the text and key
int encipher(string text, string key)
{
    int value;
    char ci;
    int n = strlen(text);
    char ciphertext[n];

    for (int i = 0; i < n; i++)
    {
        char c = text[i];
        bool alphanumeric = isalpha(text[i]);

        if (alphanumeric && isupper(c))
        {
            value = c - 65;
            ci = toupper(key[value]);
        }
        else if (alphanumeric && islower(c))
        {
            value = c - 97;
            ci = tolower(key[value]);
        }
        else
        {
            ci = c;
        }
        ciphertext[i] = ci;
    }
    //getting the ciphertext
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}
