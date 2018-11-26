void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2]; // Pivo
     
    while(i <= j) {
        while(a[i] < x && i < right) { // buscando valores maiores que o pivo 
            i++;
        }
        while(a[j] > x && j > left) { // Buscando valores menores que o pivo
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
