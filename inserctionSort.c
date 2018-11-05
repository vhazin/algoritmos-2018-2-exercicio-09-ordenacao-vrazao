#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *arr, int n);

int main(void)
{
    clock_t start, stop;
    int length, *array, x;
    printf("Choose the length of your array: ");
    scanf("%d", &length);
    printf("Now type your array with numbers and an space between: ");
    array = (int *)malloc(length * sizeof(int));
    for (x = 0; x < length; x++)
        scanf("%d", &array[x]);
    start = clock();
    insertionSort(array, length);
    stop = clock();
    printf("\nThis algorithm runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    for (x = 0; x < length; x++)
        printf(" %d ", array[x]);

    return 0;
}

void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}