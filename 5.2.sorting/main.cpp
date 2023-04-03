#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

void fullRandomNums(int *arr, const size_t size, const int left = -100, const int right = 100)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (right - left + 1) + left;
    }
}

bool isIncreasingArray(const int *arr, const size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

double bubbleSort(int *arr, const size_t size)
{
    clock_t start = clock();
    for (int border = size; border > 0; border--)
    {
        for (int i = 0; i < border - 1; i++)
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
    int left = 0, right = size - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        }
        right--;
        for (int i = right; left < i; i--)
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
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[size - 1]);
}

int *copyArray(int *arr, const size_t size)
{
    int *arrCopy = new int[(int)size];
    for (int i = 0; i < size; i++)
        arrCopy[i] = arr[i];
    return arrCopy;
}

int main()
{
    int n = 5000;
    int *arr = new int[n];
    for (int i = 0; i < 20; i++)
    {
        fullRandomNums(arr, n);

        int *arrCopy = copyArray(arr, n);
        double bubbleSortTime = bubbleSort(arrCopy, n);

        printf("Bubble sort:\ntime - %lf,\nSorted: %d\n\n", bubbleSortTime, isIncreasingArray(arrCopy, n));

        arrCopy = copyArray(arr, n);
        double shakerSortTime = shakerSort(arrCopy, n);

        printf("Shaker sort:\ntime - %lf,\nSorted: %d\n\n", shakerSortTime, isIncreasingArray(arrCopy, n));
        delete[] arrCopy;
    }

    delete[] arr;

    return 0;
}