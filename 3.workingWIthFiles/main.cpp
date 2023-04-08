#include <stdio.h>
#include <stdlib.h>

void checkFileOpening(FILE * file) {
    if(file == NULL) {
        perror("File opening error.");
        getchar();
        exit(-1);
    }
}

void printFileContent(const char * filename) {
    FILE * file = fopen(filename, "r");
    checkFileOpening(file);
    char c;
    while(fscanf(file, "%c", &c) != EOF) {
        printf("%c", c);
    }
    fclose(file);
}

void randomTextFile(const char * filename, const size_t length) {
    FILE * file = fopen(filename, "w");
    checkFileOpening(file);

    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for(size_t i = 0; i < length; i++) {
        char c = symbols[rand() % 62];
        fprintf(file, "%c", c);
    }
    fclose(file);
}


void sortSymbols(
    const char * mainFileName, 
    const char * lettersFileName, 
    const char * digitsFileName
)
{
    FILE * mainfile = fopen(mainFileName, "r");
    FILE * letters = fopen(lettersFileName, "w");
    FILE * digits = fopen(digitsFileName, "w");
    checkFileOpening(mainfile);
    checkFileOpening(letters);
    checkFileOpening(digits);
    
    char c;
    while(fscanf(mainfile, "%c", &c) != EOF) {
        if(c >= 48 && c <= 57) {
            fprintf(digits, "%c", c);
        }
        else if(c >= 65 && c <= 90 || c >= 97 && c <= 122) {
            fprintf(letters, "%c", c);
        }
    }

    fclose(mainfile);
    fclose(letters);
    fclose(digits);
}

int main() {
    randomTextFile(
        "files\\mainfile.txt", 
        100
    );
    
    sortSymbols(
        "files\\mainfile.txt", 
        "files\\letters.txt", 
        "files\\digits.txt"
    );
    
    printf("Main:\n");
    printFileContent("files\\mainfile.txt");
    printf("\n");
    printf("digits:\n");
    printFileContent("files\\digits.txt");
    printf("\n");

    printf("letters:\n");
    printFileContent("files\\letters.txt");
    printf("\n");


    
    return 0;
}