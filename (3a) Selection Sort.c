#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int op_count;

/* Selection Sort implementation */
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            ++op_count;           /* comparison count */
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        /* swap arr[i] and arr[min] */
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

/* Tester/Plotter: generates best/worst/avg counts */
void plotter(void) {
    FILE *f = fopen("s.txt", "a");
    srand(time(NULL));

    for (int n = 10; n <= 100; n += 10) {
        int *arr = malloc(n * sizeof(int));
        if (!arr) { exit(EXIT_FAILURE); }

        /* General case: random (even you can give ascending or descending array too */
        for (int i = 0; i < n; ++i) arr[i] = rand() % n;
        op_count = 0;
        selection_sort(arr, n);
        fprintf(f, "%d\t%d\n", n, op_count);

        free(arr);
    }
    fclose(f);
}

/* Tester demonstration */
void tester(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input.\n");
        return;
    }
    int *arr = malloc(n * sizeof(int));
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    op_count = 0;
    selection_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\nComparisons performed: %d\n", op_count);
    free(arr);
}

int main(void) {
    /* 1) Generate data files for plotting */
    plotter();

    /* 2) Run interactive demo */
    tester();

    return 0;
}
