#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int count;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int beg, int end) {
    int pivot = arr[beg];
    int i = beg, j = end + 1;
    do {
        do { count++; i++; } while (i <= end && arr[i] < pivot);
        do { count++; j--; } while (j >= beg && arr[j] > pivot);
        if (i < j) swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[beg], &arr[j]);
    return j;
}

void quick(int arr[], int beg, int end) {
    if (beg < end) {
        int split = partition(arr, beg, end);
        quick(arr, beg, split - 1);
        quick(arr, split + 1, end);
    }
}

void plotter(void) {
    FILE *fb = fopen("bc.txt", "a");
    FILE *fa = fopen("ac.txt", "a");
    FILE *fw = fopen("wc.txt", "a");
    srand(time(NULL));
    for (int n = 2; n <= 1024; n *= 2) {
        int *arr = malloc(n * sizeof(int));
        /* best case: all elements equal */
        for (int i = 0; i < n; ++i) arr[i] = 1;
        count = 0;
        quick(arr, 0, n - 1);
        fprintf(fb, "%d\t%d\n", n, count);
        /* average case: random elements */
        for (int i = 0; i < n; ++i) arr[i] = rand() % n;
        count = 0;
        quick(arr, 0, n - 1);
        fprintf(fa, "%d\t%d\n", n, count);
        /* worst case: sorted ascending */
        for (int i = 0; i < n; ++i) arr[i] = i + 1;
        count = 0;
        quick(arr, 0, n - 1);
        fprintf(fw, "%d\t%d\n", n, count);
        free(arr);
    }
    fclose(fb);
    fclose(fa);
    fclose(fw);
}

int main(void) {
    plotter();
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    count = 0;
    quick(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\nNumber of operations: %d\n", count);
    printf("\n%d\n", count);
    free(arr);
    return 0;
}
