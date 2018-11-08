#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *a, int l, int h)
{
    if (h - l == 1)
    {
        if (a[l] > a[h])
        {
            int t = a[l];
            a[l] = a[h];
            a[h] = t;
        }
    }
    else if (h == l)
        return;
    else if (h > l)
    {
        int size = h - l + 1;
        int m = l + (h - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);
        int b[size];
        int k = 0;
        int i = l;
        int j = m + 1;
        while (i <= m && j <= h)
            if (a[i] <= a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];

        while (i <= m)
            b[k++] = a[i++];

        while (j <= h)
            b[k++] = a[j++];

        for (k = 0; k < size; k++)
        {
            a[l + k] = b[k];
        }
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
    mergeSort(array, 0, length - 1);
    for (x = 0; x < length; x++)
        printf(" %d ", array[x]);
    return 0;
}
