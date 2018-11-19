#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp);
void selectionSort(int *arr, int n);
void mergeSort(int *a, int l, int h);
void insertionSort(int *arr, int n);
void bubbleSort(int *a, int size);
void build_heap(int *array, int length);
void heapify(int *array, int subIndice, int length);
void mergeSort(int *a, int l, int h);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main(void)
{
    clock_t start, stop;
    int length, *array, *arrayCopy, x;

    scanf("%d", &length);
    array = (int *)malloc(length * sizeof(int));
    arrayCopy = (int *)malloc(length * sizeof(int));

    for (x = 0; x < length; x++)
        scanf("%d", &array[x]);

    // Selection Sort
    for (x = 0; x < length; x++)
        arrayCopy[x] = array[x];
    start = clock();
    selectionSort(arrayCopy, length);
    stop = clock();
    printf("\nSelection Sort runned in runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    // Inserction Sort
    for (x = 0; x < length; x++)
        arrayCopy[x] = array[x];
    start = clock();
    insertionSort(arrayCopy, length);
    stop = clock();
    printf("\nInserction Sort runned in runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    // bubbleSort Sort
    for (x = 0; x < length; x++)
        arrayCopy[x] = array[x];
    start = clock();
    bubbleSort(arrayCopy, length);
    stop = clock();
    printf("\nBubble Sort runned in runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    // Heap Sort
    for (x = 0; x < length; x++)
        arrayCopy[x] = array[x];
    start = clock();
    build_heap(arrayCopy, length);
    stop = clock();
    printf("\nHeap Sort runned in runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    // Merge Sort
    for (x = 0; x < length; x++)
        arrayCopy[x] = array[x];
    start = clock();
    mergeSort(arrayCopy, 0, length - 1);
    stop = clock();
    printf("\nMerge Sort runned in runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    for (x = 0; x < length; x++)
        arrayCopy[x] = array[x];
    start = clock();
    quickSort(arrayCopy, 0, length - 1);
    stop = clock();
    printf("\nQuick Sort runned in runned in: %f s", (double)(stop - start) / CLOCKS_PER_SEC);

    printf("\n");

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
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
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

void build_heap(int *array, int length)
{
    int i, temp;
    for (i = length / 2; i >= 0; i--)
        heapify(array, i, length);

    for (i = length - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, 0, i);
    }
}

void heapify(int *array, int subIndice, int length)
{
    int left = 2 * subIndice + 1;
    int right = 2 * subIndice + 2;
    int largest, temp;
    if (left < length && array[left] > array[subIndice])
        largest = left;
    else
        largest = subIndice;

    if (right < length && array[right] > array[largest])
        largest = right;
    if (largest != subIndice)
    {
        temp = array[subIndice];
        array[subIndice] = array[largest];
        array[largest] = temp;
        heapify(array, largest, length);
    }
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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}