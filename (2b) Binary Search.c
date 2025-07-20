#include <stdio.h>
#include <stdlib.h>

int op_count;

/* Recursive binary search that counts comparisons */
int binary_search(int arr[], int low, int high, int key) {
    op_count++;
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    op_count++;
    if (arr[mid] == key) {
        return mid;
    } else if (key < arr[mid]) {
        return binary_search(arr, low, mid - 1, key);
    } else {
        return binary_search(arr, mid + 1, high, key);
    }
}

/* Tester & plotter: writes best/worst case counts to separate files */
void plotter(void) {
    FILE *fb = fopen("binsearch_best.txt",  "a");
    FILE *fw = fopen("binsearch_worst.txt", "a");
    for (int n = 2; n <= 1024; n *= 2) {
        int *arr = malloc(n * sizeof(int));
        /* Fill with sorted values 1..n */
        for (int i = 0; i < n; ++i) arr[i] = i + 1;

        /* Best case: key at middle */
        op_count = 0;
        binary_search(arr, 0, n - 1, arr[n/2]);
        fprintf(fb, "%d\t%d\n", n, op_count);

        /* Worst case: key not present */
        op_count = 0;
        binary_search(arr, 0, n - 1, -1);
        fprintf(fw, "%d\t%d\n", n, op_count);

        free(arr);
    }
    fclose(fb);
    fclose(fw);
}

/* tester for binary search */
void tester(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size.\n");
        return;
    }
    int *arr = malloc(n * sizeof(int));
    
    printf("Enter %d elements in increasing order:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    op_count = 0;
    int idx = binary_search(arr, 0, n - 1, key);
    if (idx == -1) {
        printf("Key not found (comparisons: %d).\n", op_count);
    } else {
        printf("Key found at index %d (comparisons: %d).\n", idx, op_count);
    }
    free(arr);
}

int main(void) {
    /* Generate data files for plotting */
    plotter();

    /* Then allow an interactive search demo */
    tester();

    return 0;
}
