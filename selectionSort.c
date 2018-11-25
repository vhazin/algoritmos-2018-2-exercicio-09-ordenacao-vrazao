#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp);
void selectionSort(int *arr, int n);

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
    selectionSort(array, length);
    stop = clock();

    for (x = 0; x < length; x++)
        printf(" %d ", array[x]);
    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int *arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < n; j++) // varre o array procurando o menor valor e compara com o indice i
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]); // Caso min_idx != i, fazer a troca.
    }
}
