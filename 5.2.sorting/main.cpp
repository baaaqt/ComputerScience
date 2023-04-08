#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

void fillRandomNums(int *arr, const size_t size, const int left = -100, const int right = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (right - left + 1) + left;
    }
}

bool isIncreasingArray(const int *arr, const size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

double bubbleSort(int *arr, const size_t size)
{
    clock_t start = clock();
    for (size_t border = size; border > 0; border--)
    {
        for (size_t i = 0; i < border - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        }
    }
    clock_t end = clock();
    return (double)(end - start) / ((clock_t)1000);
}

double shakerSort(int *arr, const size_t size)
{
    clock_t start = clock();
    size_t left = 0, right = size - 1;
    while (left < right)
    {
        for (size_t i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        }
        right--;
        for (size_t i = right; left < i; i--)
        {
            if (arr[i] < arr[i - 1])
                std::swap(arr[i], arr[i - 1]);
        }
        left++;
    }
    clock_t end = clock();
    return (double)(end - start) / ((clock_t)1000);
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

int *copyArray(int *arr, const size_t size)
{
    int *arrCopy = (int *) malloc(sizeof(int) * size);
    for (size_t i = 0; i < size; i++)
        arrCopy[i] = arr[i];
    return arrCopy;
}

int main()
{
    int n = 25000;
    int *arr = (int *) malloc(sizeof(int) *n);
    for (int i = 0; i < 20; i++)
    {
        fillRandomNums(arr, n);

        int *arrCopy = copyArray(arr, n);
        double bubbleSortTime = bubbleSort(arrCopy, n);

        printf("Bubble sort:\ntime - %lf,\nSorted: %d\n\n", bubbleSortTime, isIncreasingArray(arrCopy, n));

        arrCopy = copyArray(arr, n);
        double shakerSortTime = shakerSort(arrCopy, n);

        printf("Shaker sort:\ntime - %lf,\nSorted: %d\n\n", shakerSortTime, isIncreasingArray(arrCopy, n));
        free(arrCopy);
    }

    free(arr);

    return 0;
}