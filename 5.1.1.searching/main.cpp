#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void fillIncreasingNums(int *arr, const size_t size, const int left = -100, const int right = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (right - left + 1) + left;
    }
    std::sort(arr, arr + size);
}

void printArray(const int *arr, const size_t size)
{
    printf("[");
    for (size_t i = 0; i < size - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[size - 1]);
}

int binarySearch(const int *arr, const size_t size, const int key)
{
    size_t left = 0;
    size_t right = size - 1;
    while (left <= right)
    {
        size_t index = (left + right) / 2;

        if (arr[index] < key)
            left = index + 1;
        else if (arr[index] > key)
            right = index - 1;
        else
            return index;
    }
    return -1;
}

int main()
{
    srand(time(0));

    size_t n;
    printf("Input n: ");
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    fillIncreasingNums(arr, n);
    printArray(arr, n);
    
    int key;
    printf("\nInput k: ");
    scanf("%d", &key);
    
    printf("Index = %d\n", binarySearch(arr, n, key));
    
    free(arr);
    return 0;
}