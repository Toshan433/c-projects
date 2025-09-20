# Download the CS50 library from https://github.com/cs50/libcs50

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Welcoming
    printf("Make letter capital.\n");

    // Ask for their input
    char *input = get_string("Input: ");

    // Get other memory for new Output
    char *output = malloc(strlen(input + 1));

    // Copy Input to Output
    int n = strlen(input);
    for (int i = 0; i <= n; i++)
    {
        output[i] = input[i];
    }

    // Capatilize
    int p = strlen(output);
    for (int j = 0; j <= p; j++)
    {
        output[j] = toupper(output[j]);
    }

    // Print out the result
    printf("Output: %s\n", output);

    // Free malloc memory
    free(output);
}
