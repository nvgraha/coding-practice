#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in buffer
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[BLOCK_SIZE];

    // File pointer to recovered images
    FILE *output = NULL;

    // 'string' of file's name
    char *filename = malloc(8 * sizeof(char));

    // Keep track of JPEG generated
    int file_index = 0;

    // While there's still data left to read from the memory card
    while (fread(&buffer, sizeof(uint8_t), 512, card))
    {
        // Looking for JPEG’s signatures
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Closing file after encounter another signature
            if (file_index > 0)
            {
                fclose(output);
            }

            // Write JPEG’s file name
            sprintf(filename, "%03i.jpg", file_index);

            // Open a new file for writing
            output = fopen(filename, "w");

            // Index of the JPEG found
            file_index++;
        }

        // Create JPEGs from the data to output file
        if (output != NULL)
        {
            fwrite(&buffer, sizeof(uint8_t), 512, output);
        }
    }

    // Free malloc and close files
    free(filename);
    fclose(card);
    fclose(output);
}
