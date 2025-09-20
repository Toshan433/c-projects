# Download the CS50 library from https://github.com/cs50/libcs50

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("What's your height? ");
    }
    while (height > 8 || height <= 0);

    for(int i = 0; i < height; i++)
    {
        for(int j = 1; j < height-i; j++)
        {
            printf(" ");
        }
        for(int p = 0; p <= i; p++)
        {
            printf("#");
        }
        printf("  ");
        for(int x = 0; x <= i; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}
