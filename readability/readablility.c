# Download the CS50 library from https://github.com/cs50/libcs50

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    // Input for text
    string text = get_string("Text :");

    // count variables
    int l = 0;
    int w = 0;
    int s = 0;

    // Length of text
    int length = strlen(text);

    // Length of nothing
    for (int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            l++;
        }

        if (i == 0 || (isspace(text[i - 1]) && !isspace(text[i])))
        {
        w++;
        }

        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
    }

    // Average of nothings
    float L = ((float)l/w)*100;
    float S = ((float)s/w)*100;

    // Count the grade
    int index = (int)round(0.0588 * L - 0.296 * S - 15.8);

    // Result
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
