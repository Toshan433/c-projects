# Download the CS50 library from https://github.com/cs50/libcs50

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change :");
    }
    while (change <= 0);

    int quarter = change / 25;
    int dimes = (change - (quarter * 25)) / 10;
    int nickel = (change - (quarter * 25) - (dimes * 10)) / 5;
    int penny = (change - (quarter * 25) - (dimes * 10) - (nickel * 5)) / 1;

    int total_coin = 0;
    total_coin += quarter;
    total_coin += dimes;
    total_coin += nickel;
    total_coin += penny;

    if (quarter > 0 && quarter < 2)
    {
        printf("%i Quarter ", quarter);
    }
    else if (quarter >= 2)
    {
        printf("%i Quarters ", quarter);
    }
    if (dimes > 0 && dimes < 2)
    {
        printf("%i Dime ", dimes);
    }
    else if (dimes >= 2)
    {
        printf("%i Dimes ", dimes);
    }
    if (nickel > 0 && nickel < 2)
    {
        printf("%i Nickel ", nickel);
    }
    else if (nickel >= 2)
    {
        printf("%i Nickels ", nickel);
    }
    if (penny > 0 && penny < 2)
    {
        printf("%i Penny ", penny);
    }
    else if (penny >= 2)
    {
        printf("%i Pennies ", penny);
    }
    printf("\n");
    printf("Total coins: %i", total_coin);
    printf("\n");
}
