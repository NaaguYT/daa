#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int op_count;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int value = arr[i];
        int j = i - 1;
        /* count one comparison for entering the while */
        while (j >= 0 && (op_count++ && arr[j] > value)) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = value;
    }
}

void plotter(void) {
    FILE *fb = fopen("is_best.txt",  "a");
    FILE *fw = fopen("is_worst.txt", "a");
    FILE *fa = fopen("is_avg.txt",   "a");
    srand(time(NULL));

    for (int n = 10; n <= 100; n += 10) {
        int *arr = malloc(n * sizeof(int));

        /* Best case: already sorted ascending */
        for (int i = 0; i < n; ++i) arr[i] = i + 1;
        op_count = 0;
        insertion_sort(arr, n);
        fprintf(fb, "%d\t%d\n", n, op_count);

        /* Worst case: reverse sorted */
        for (int i = 0; i < n; ++i) arr[i] = n - i;
        op_count = 0;
        insertion_sort(arr, n);
        fprintf(fw, "%d\t%d\n", n, op_count);

        /* Average case: random */
        for (int i = 0; i < n; ++i) arr[i] = rand() % n;
        op_count = 0;
        insertion_sort(arr, n);
        fprintf(fa, "%d\t%d\n", n, op_count);

        free(arr);
    }

    fclose(fb);
    fclose(fw);
    fclose(fa);
}

void tester(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size.\n");
        return;
    }
    int *arr = malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    op_count = 0;
    insertion_sort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of shifts/comparisons: %d\n", op_count);
    free(arr);
}

int main(void) {
    plotter();
    tester();
    return 0;
}
