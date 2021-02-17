#include <stdio.h>
#include <math.h>
#include <cs50.h>

float dollars;
int coins = 0;

int main(void)
{
    //Prompt user for Cash owned
    do
    {
        dollars = get_float("Cash owed: ");
    }
    while (dollars <= 0);

    //Rounding the cents to the nearest penny
    int cents = round(dollars * 100);

    //Deducting the values from the bigger to the smaller
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents --;
        }
        coins++;
    }
    //Print the minimal amount of coins
    printf("%i\n", coins);
}
