# Download the CS50 library from https://github.com/cs50/libcs50

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int score_count(string s);

int main(void)
{
    string player1 = get_string("Player1 :");
    string player2 = get_string("Player2 :");

    int score1 = score_count(player1);
    int score2 = score_count(player2);

    if (score1 > score2)
    {
        printf("Player1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_count(string s)
{
    int total_score = 0; 

    for (int i = 0; i < strlen(s); i++)
    {
        int value = 0;

        char plyr = toupper(s[i]);

        if (plyr == 'A' || plyr == 'E' || plyr == 'I' || plyr == 'L' || plyr == 'M' || plyr == 'O' || plyr == 'R' || plyr == 'S' || plyr == 'T' || plyr == 'U')
        {
            value += 1;
        }
        else if (plyr == 'B' || plyr == 'C' || plyr == 'M' || plyr == 'P')
        {
            value += 3;
        }
        else if (plyr == 'D' || plyr == 'G')
        {
            value += 2;
        }
        else if (plyr == 'F' || plyr == 'H' || plyr == 'V' || plyr == 'W' || plyr == 'Y')
        {
            value += 4;
        }
        else if (plyr == 'J' || plyr == 'X')
        {
            value += 8;
        }
        else if (plyr == 'K')
        {
            value += 5;
        }
        else if (plyr == 'Q' || plyr == 'Z')
        {
            value += 10;
        }

        total_score += value;
    }

    return total_score;
}
