#include <stdio.h>
#include <stdlib.h>

void checkFileOpening(FILE * file) {
    if(file == NULL) {
        perror("File opening error.");
        getchar();
        exit(-1);
    }
}

void randomTextFile(const char * filename, const unsigned int length) {
    FILE * file = fopen(filename, "w");
    checkFileOpening(file);

    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < length; i++) {
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
        "/home/baaaqt/Programming/CPPProjects/ComputerScience/3.workingWIthFiles/mainfile.txt", 
        1000
    );
    
    sortSymbols(
        "/home/baaaqt/Programming/CPPProjects/ComputerScience/3.workingWIthFiles/mainfile.txt", 
        "/home/baaaqt/Programming/CPPProjects/ComputerScience/3.workingWIthFiles/letters.txt", 
        "/home/baaaqt/Programming/CPPProjects/ComputerScience/3.workingWIthFiles/digits.txt"
    );
    
    
    return 0;
}