#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);

            // Update pixel values
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0, sumGreen = 0, sumRed = 0;
            float counter = 0.00;

            // Get neighboring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // Ensure neighboring pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 ||
                        currentY > (width - 1))
                    {
                        continue;
                    }

                    // Add RGB values of neighboring pixels to the total RGB values
                    sumBlue += image[currentX][currentY].rgbtBlue;
                    sumGreen += image[currentX][currentY].rgbtGreen;
                    sumRed += image[currentX][currentY].rgbtRed;

                    counter++;
                }
            }

            // Compute the new value for a pixel by taking the average of neighboring pixels
            copy[i][j].rgbtBlue = round(sumBlue / counter);
            copy[i][j].rgbtGreen = round(sumGreen / counter);
            copy[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    // Update image with the new pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blueX = 0, greenX = 0, redX = 0;
            int blueY = 0, greenY = 0, redY = 0;

            // Loop over 3x3 neighboring pixels
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // Ensure neighboring pixel is valid
                    if (i - 1 + x < 0 || i - 1 + x > (height - 1) || j - 1 + y < 0 ||
                        j - 1 + y > (width - 1))
                    {
                        continue;
                    }

                    // Compute Gx for each channel
                    blueX += (image[i - 1 + x][j - 1 + y].rgbtBlue * Gx[x][y]);
                    greenX += (image[i - 1 + x][j - 1 + y].rgbtGreen * Gx[x][y]);
                    redX += (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);

                    // Compute Gy for each channel
                    blueY += (image[i - 1 + x][j - 1 + y].rgbtBlue * Gy[x][y]);
                    greenY += (image[i - 1 + x][j - 1 + y].rgbtGreen * Gy[x][y]);
                    redY += (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                }
            }

            // Compute the Sobel operator for each RGB channels per pixel by calculating the square
            // root of Gx^2 + Gy^2, rounded the value and capped at 255
            int blue = fmin(255, round(sqrt((blueX * blueX) + (blueY * blueY))));
            int green = fmin(255, round(sqrt((greenX * greenX) + (greenY * greenY))));
            int red = fmin(255, round(sqrt((redX * redX) + (redY * redY))));

            // Update temp's pixel
            temp[i][j].rgbtBlue = blue;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtRed = red;
        }
    }

    // Update original image (pixel)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
