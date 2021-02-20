#include <stdio.h>
#include <cs50.h>

//Prototype
void draw(int height, int initial_height);

int main(void)
{
    int h;
    //Prompt user for height, number should be 1-8
    do
    {
        h = get_int("Enter pyramid height(1-8): \n");
    }
    while (h < 1 || h > 8);

    draw(h, h);
}

void draw(int height, int initial_height)
{
    if (height == 0)
    {
        return;
    }

    //Drawing the pyramid
    draw(height - 1, initial_height);

    for (int i = 0; i < initial_height - height; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < height; i++)
    {
        //Adding the hashes
        printf("#");
    }
    printf("\n");
}
