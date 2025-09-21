# Donwload the CS50 library from https://github.com/cs50/libcs50

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    typedef uint8_t BYTE;
    BYTE header[HEADER_SIZE];

    fread(&header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(&header, sizeof(BYTE), HEADER_SIZE, output);

    typedef int16_t SAMPLE;
    SAMPLE sample;

    while (fread(&sample, sizeof(SAMPLE), 1, input) == 1)
    {
        sample = (sample*factor);
        fwrite(&sample, sizeof(SAMPLE), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
