#include <stdlib.h>
#include <stdio.h>

void checkFileOpening(FILE * file) {
    if(file == NULL) {
        perror("File opening error.");
        getchar();
        exit(-1);
    }
}

struct Student {
    char name[20];
    char lastName[20];
    int group;
    int marks[3];
};

Student * getStudentsData(const char * filename) {
    Student * arr = (Student *) malloc(sizeof(Student) * 50);
    FILE * file = fopen(filename,"r");
    checkFileOpening(file);
    for(int i = 0; i < 50; i++) {
        fscanf(file, "%s%s%d", &arr[i].name, &arr[i].lastName, &arr[i].group);
        for(int j = 0; j < 3; j++) {
            fscanf(file, "%d", &arr[i].marks[j]);
        }
    }
    fclose(file);
    return arr;
}

void showResults(const Student * arr, const int k) {
    for(int i = 0; i < 50; i++) {
        if(arr[i].group == k)
        {
            printf("Name: %s %s,\nGroup: %d,\n", arr[i].name, arr[i].lastName, arr[i].group);
            printf("Marks: [%d, %d, %d].\n\n", arr[i].marks[0], arr[i].marks[1], arr[i].marks[2]);
            printf("\n");
        }
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

int main() {
    char filename[] = "data.txt";
    Student * arr = getStudentsData(filename);
    int groupNumber;
    printf("Input group number: ");
    scanf_s("%d", &groupNumber);
    showResults(arr, groupNumber);
    return 0;
}