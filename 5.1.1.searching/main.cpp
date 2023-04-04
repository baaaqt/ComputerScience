#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void fillIncreasingNums(int *arr, const size_t size, const int left = -100, const int right = 100)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (right - left + 1) + left;
    }
    std::sort(arr, arr + size);
}

void printArray(const int *arr, const size_t size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[size - 1]);
}

int binarySearch(const int *arr, const size_t size, const int key)
{
    unsigned int left = 0;
    unsigned int right = size - 1;
    while (left <= right)
    {
        int index = (left + right) / 2;

        if (arr[index] < key)
            left++;
        else if (arr[index] > key)
            right--;
        else
            return index;
    }
    return -1;
}

int main()
{
    srand(time(0));

    int n;
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