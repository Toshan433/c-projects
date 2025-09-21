#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float avg1 = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen)/3.0;
            int avg = round(avg1);

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed  = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            float sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            float sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed  = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
RGBTRIPLE copy[height][width];
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        copy[i][j] = image[i][j];
    }
}

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        int totalRed = 0;
        int totalGreen = 0;
        int totalBlue = 0;
        int count = 0;

        for (int di = -1; di <= 1; di++)
        {
7            for (int dj = -1; dj <= 1; dj++)
            {
                int ni = i + di;
                int nj = j + dj;
                
                if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                {
                    totalRed += copy[ni][nj].rgbtRed;
                    totalGreen += copy[ni][nj].rgbtGreen;
                    totalBlue += copy[ni][nj].rgbtBlue;
                    count++;
                }
            }
        }

        image[i][j].rgbtRed = round((float) totalRed / count);
        image[i][j].rgbtGreen = round((float) totalGreen / count);
        image[i][j].rgbtBlue = round((float) totalBlue / count);
    }
    }
}
