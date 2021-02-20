#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Prototype
int encipher(string plaintext, int key);
int test_arguments(int arguments, string key[]);

// Confirms there are  args included to run the program
int main(int argc, string argv[])
{
    int test = test_arguments(argc, argv);
    if (test)
    {
        return test;
    }
    else
    {
        //Promting for a plaintext
        string plaintext = get_string("plaintext: ");
        int key = atoi(argv[1]);
        return encipher(plaintext, key);
    }
}

//testing args
int test_arguments(int arguments, string key[])
{
    //Confirming args are 2
    if (arguments != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    for (int i = 0, n = strlen(key[1]); i < n; i++)
    {
        if (isalpha(key[1][i]))
        {
            printf("Usage: ./caesar key.\n");
            return 1;
        }
    }
    return 0;
}

//enciphering text and key
int encipher(string plaintext, int key)
{
    printf("ciphertext: ");
    char ci;
    int n = strlen(plaintext);
    char ciphertext[n];
    for (int i = 0; i < n; i++)
    {
        int c = plaintext[i];

        //Checking if the char is alphabet
        if (isalpha(c))
        {
            ci = c + key % 26;
            bool test_boundaries = islower(ci) || isupper(ci);
            if (!test_boundaries)
            {
                ci -= 26;
            }
        }
        else
        {
            ci = c;
        }
        ciphertext[i] = ci;
    }
    // Returns an error message if the code isn't executed in proper format
    printf("%s\n", ciphertext);
    return 0;
}
