#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *a, int l, int h);

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
    mergeSort(array, 0, length - 1);
    stop = clock();
    for (x = 0; x < length; x++)
        printf(" %d ", array[x]);
    printf("\nThis algorithm runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);
    return 0;
}

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
        return; // Condição de parada unitária
    else if (h > l)
    {
        int size = h - l + 1;
        int m = l + (h - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h); // Até aqui ele saiu quebrando o vetor em pedaços menores
        int b[size];
        int k = 0;
        int i = l;
        int j = m + 1;
        while (i <= m && j <= h)
            if (a[i] <= a[j]) // Se o da esquerda for menor
                b[k++] = a[i++]; // Joga o da esquerda em vez do da direita
            else
                b[k++] = a[j++]; // Se nao joga o da direita

        while (i <= m)
            b[k++] = a[i++]; // Aqui o restante do array ja ta ordenado então é só copiar

        while (j <= h)
            b[k++] = a[j++]; // E depois copiar o restante ordenado da direita

        for (k = 0; k < size; k++)
        {
            a[l + k] = b[k]; // Agora passa do auxiliar pro principal
        }
    }
}
