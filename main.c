#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;
int randInt(int min, int max) {return rand() % (max - min + 1) + min;}
void generate_key(BYTE key[256]);
void retrieve_key(BYTE buffer[256], BYTE key[256]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    if (argc != 4) {
        printf("correct format is <--e/--d> <input path> <output path>\n");
        return 1;
    }
    if (strcmp(argv[1], "--e") != 0 && strcmp(argv[1], "--d") != 0) {
        printf("correct format is <--e/--d> <input path> <output path>\n");
        return 2;
    }

    FILE *input_file;
    FILE *output_file;
    BYTE buffer[1];
    BYTE key[256];
    if (!(input_file = fopen(argv[2], "rb"))) {
        printf("input file couldn't be found\n");
        return 3;
    }
    if (!(output_file = fopen(argv[3], "wb"))) {
        fclose(input_file);
        printf("input file couldn't be opened\n");
        return 4;
    }

    if (strcmp(argv[1], "--e") == 0) {
        generate_key(key);
        for (int i = 0; i < 256; i++) fwrite(&key[i], 1, 1, output_file);
    } else {
        BYTE buffer[256];
        fread(buffer, 1, 256, input_file);
        retrieve_key(buffer, key);

        int sum = 0;
        for (int i = 0; i < 256; i++) sum += key[i];
        if (sum != 32640) {
            fclose(input_file);
            fclose(output_file);
            printf("input file isn't encrypted with this program\n");
            return 5;
        }
    }

    while (fread(buffer, 1, 1, input_file) > 0) {
        fwrite(&key[buffer[0]], 1, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    
    return 0;
}

void generate_key(BYTE key[256]) {
    for (int i = 0; i < 256; i++)
        key[i] = i;
    for (int i = 0; i < randInt(10000, 50000); i++) {
        BYTE a = randInt(0, 255);
        BYTE b = randInt(0, 255);
        BYTE temp = key[a];
        key[a] = key[b];
        key[b] = temp;
    }
}

void retrieve_key(BYTE buffer[256], BYTE key[256]) {
    for (int i = 0; i < 256; i++)
        key[buffer[i]] = i;
}