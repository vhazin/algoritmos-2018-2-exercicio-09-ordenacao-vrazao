#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a, int size)
{
    for (int i = size; i > 0; i--)
        for (int j = 0; j < i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main(void)
{
    int length, *array, x;
    printf("Choose the length of your array: ");
    scanf("%d", &length);
    printf("Now type your array with numbers and an space between: ");
    array = (int *)malloc(length * sizeof(int));
    for (x = 0; x < length; x++)
        scanf("%d", &array[x]);
    bubbleSort(array, length);
    for (x = 0; x < length; x++)
        printf(" %d ", array[x]);
    return 0;
}