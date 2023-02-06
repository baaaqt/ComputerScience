#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void fullIncreasingNums(int *arr, const size_t size, const int left = -100, const int right = 100)
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

int binarySearch(const int *arr, const size_t size, const int k)
{
    unsigned int left = 0;
    unsigned int right = size - 1;
    while (left <= right)
    {
        int index = (left + right) / 2;

        if (arr[index] < k)
            left++;
        else if (arr[index] > k)
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
    int *arr = new int[n];
    fullIncreasingNums(arr, n);
    printArray(arr, n);
    
    int k;
    printf("\nInput k: ");
    scanf("%d", &k);
    
    printf("\n%d\n", binarySearch(arr, n, k));
    delete[] arr;
    return 0;
}