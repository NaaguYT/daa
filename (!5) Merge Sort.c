#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int op_count;

void merge(int arr[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i)
      L[i] = arr[beg + i];
    for (int j = 0; j < n2; ++j)
      R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = beg;

    while (i < n1 && j < n2) {
        op_count++;
        if (L[i] <= R[j])
          arr[k++] = L[i++];
        else
          arr[k++] = R[j++];
    }
    while (i < n1)
      arr[k++] = L[i++];
    while (j < n2)
      arr[k++] = R[j++];
}

void mergesort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void worst(int arr[], int beg, int end) {
    int len = end - beg + 1;
    if (len < 2) return;

    int mid = (beg + end) / 2;
    int n1  = mid - beg + 1;
    int n2  = end - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    /* Split out alternating elements into L and R */
    for (int i = 0; i < n1; i++) {
        L[i] = arr[beg + 2*i];  /* take even-indexed (relative) elements */
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[beg + 2*j + 1];  /* take odd-indexed (relative) elements */
    }

    /* Recurse on each half to create worst-case for their sizes */
    worst(L, 0, n1 - 1);
    worst(R, 0, n2 - 1);

    /* Write them back into arr[beg..end] in two halves */
    for (int i = 0; i < n1; i++) {
        arr[beg + i] = L[i];
    }
    for (int j = 0; j < n2; j++) {
        arr[beg + n1 + j] = R[j];
    }
}


void plotter() {
    FILE *fb = fopen("ms_best.txt",  "a");
    FILE *fw = fopen("ms_worst.txt", "a");
    FILE *fa = fopen("ms_avg.txt",   "a");
    srand(time(NULL));
    for (int n = 2; n <= 1024; n *= 2) {
        int *arr = malloc(n * sizeof(int));
        /* best: already sorted */
        for (int i = 0; i < n; ++i)
          arr[i] = i + 1;
        op_count = 0;
        mergesort(arr, 0, n - 1);
        fprintf(fb, "%d\t%d\n", n, op_count);

        /* worst*/
        op_count = 0;
        worst(arr, 0, n-1);
        mergesort(arr, 0, n - 1);
        fprintf(fw, "%d\t%d\n", n, op_count);


        /* avg: random */
        for (int i = 0; i < n; ++i)
          arr[i] = rand() % n;
        op_count = 0;
        mergesort(arr, 0, n - 1);
        fprintf(fa, "%d\t%d\n", n, op_count);
        free(arr);
    }
    fclose(fb);
    fclose(fw);
    fclose(fa);
}

int main(void) {
    plotter();
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    op_count = 0;
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\nNumber of operations: %d\n", op_count);
    printf("\n%d\n", op_count);
    free(arr);
    return 0;
}
