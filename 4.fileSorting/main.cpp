#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkFileOpening(FILE *file)
{
    if (file == NULL)
    {
        perror("File opening error.");
        getchar();
        exit(-1);
    }
}

void printFileContent(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char c;
    checkFileOpening(file);
    while (fscanf(file, "%c", &c) != EOF)
    {
        printf("%c", c);
    }
    fclose(file);
}

bool isEmptyFile(const char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    checkFileOpening(file);

    int x;
    if (fscanf(file, "%d", &x) == EOF)
    {
        fclose(file);
        return true;
    }

    fclose(file);
    return false;
}

void randomNumsFile(const char *filename, const int count, const int left = -100, const int right = 100)
{
    FILE *file = fopen(filename, "w");

    checkFileOpening(file);

    for (int i = 0; i < count; i++)
    {
        int num = rand() % (right - left + 1) + left;
        fprintf(file, "%d ", num);
    }
    fclose(file);
}

void split(const char *mainFileName, const char *fileNameA, const char *fileNameB)
{
    FILE *file = fopen(mainFileName, "r");
    checkFileOpening(file);

    FILE **g = (FILE **) malloc(sizeof(FILE *) * 2);
    g[0] = fopen(fileNameA, "w");
    g[1] = fopen(fileNameB, "w");
    checkFileOpening(g[0]);
    checkFileOpening(g[1]);

    int n = 0, x1, x2;
    fscanf(file, "%d", &x1);
    while (!feof(file))
    {
        fprintf(g[n], "%d ", x1);
        fscanf(file, "%d", &x2);
        while (!feof(file) && x1 <= x2)
        {
            x1 = x2;
            fprintf(g[n], "%d ", x1);
            fscanf(file, "%d", &x2);
        }
        x1 = x2;
        n = 1 - n;
    }

    fclose(file);
    fclose(g[0]);
    fclose(g[1]);
    free(g);
}

void merge(const char *mainFileName, const char *fileNameA, const char *fileNameB)
{
    FILE *file = fopen(mainFileName, "w");
    checkFileOpening(file);

    FILE **g = (FILE **) malloc(sizeof(FILE *) * 2);
    g[0] = fopen(fileNameA, "r");
    g[1] = fopen(fileNameB, "r");
    checkFileOpening(g[0]);
    checkFileOpening(g[1]);

    int x[2], y[2];
    fscanf(g[0], "%d", &x[0]);
    fscanf(g[1], "%d", &x[1]);
    while (!feof(g[0]) && !feof(g[1]))
    {
        int n;
        if (x[0] < x[1])
            n = 0;
        else
            n = 1;

        fprintf(file, "%d ", x[n]);

        fscanf(g[n], "%d", &y[n]);
        if (!feof(g[n]) && x[n] <= y[n])
            x[n] = y[n];
        else
        {
            fprintf(file, "%d ", x[1 - n]);
            fscanf(g[1 - n], "%d", &y[1 - n]);
            while (!feof(g[1 - n]) && x[1 - n] <= y[1 - n])
            {
                x[1 - n] = y[1 - n];
                fprintf(file, "%d ", x[1 - n]);
                fscanf(g[1 - n], "%d", &y[1 - n]);
            }
            x[0] = y[0];
            x[1] = y[1];
        }
    }
    while (!feof(g[0]))
    {
        fprintf(file, "%d ", x[0]);
        fscanf(g[0], "%d", &y[0]);
        x[0] = y[0];
    }
    while (!feof(g[1]))
    {
        fprintf(file, "%d ", x[1]);
        fscanf(g[1], "%d", &y[1]);
        x[1] = y[1];
    }

    fclose(file);
    fclose(g[0]);
    fclose(g[1]);
    free(g);
}

void sortFile(const char *mainFileName)
{
    const char fileNameA[] = "A.txt";
    const char fileNameB[] = "B.txt";
    split(mainFileName, fileNameA, fileNameB);

    while (!isEmptyFile(fileNameB))
    {
        merge(mainFileName, fileNameA, fileNameB);
        split(mainFileName, fileNameA, fileNameB);
    }
    if (remove(fileNameA))
    {
        perror("File removing error.\n");
        exit(-1);
    }
    if (remove(fileNameB))
    {
        perror("File removing error.\n");
        exit(-1);
    }
}

int main()
{
    srand(time(0));
    const char fileName[] = "mainfile.txt";
    randomNumsFile(fileName, 1000);

    printf("Before:\n");
    printFileContent(fileName);
    printf("\n\n");

    sortFile(fileName);

    printf("After:\n");
    printFileContent(fileName);
    printf("\n");

    return 0;
}