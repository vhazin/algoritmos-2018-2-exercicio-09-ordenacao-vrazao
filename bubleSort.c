#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *a, int size);

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
    bubbleSort(array, length);
    stop = clock();
    for (x = 0; x < length; x++)
        printf(" %d ", array[x]);

    printf("\nThis algorithm runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);
    return 0;
}

void bubbleSort(int *a, int size)
{
    for (int i = size; i > 0; i--) // coloca em ordem crescente (1,2,3,4,5...)
        for (int j = 0; j < i - 1; j++)
            if (a[j] > a[j + 1]) // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}
