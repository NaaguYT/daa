#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int op_count;

/* Bubble Sort with early exit; returns number of comparisons */
int bubble_sort(int arr[], int n) {
    op_count = 0;
    for (int i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            op_count++;  /* comparison */
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    return op_count;
}

/* Tester/Plotter: generates best/worst/avg case data */
void plotter(void) {
    FILE *fb = fopen("bb_best.txt",  "a");
    FILE *fw = fopen("bb_worst.txt", "a");
    FILE *fa = fopen("bb_avg.txt",   "a");
    if (!fb || !fw || !fa) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));

    for (int n = 10; n <= 100; n += 10) {
        int *arr = malloc(n * sizeof(int));
        if (!arr) { perror("malloc"); exit(EXIT_FAILURE); }

        /* Best case: already sorted */
        for (int i = 0; i < n; ++i) arr[i] = i + 1;
        bubble_sort(arr, n);
        fprintf(fb, "%d\t%d\n", n, op_count);

        /* Worst case: reverse sorted or  Average case: random  and avg and worst are same*/ 
        for (int i = 0; i < n; ++i) arr[i] = n - i;
        bubble_sort(arr, n);
        fprintf(fw, "%d\t%d\n", n, op_count);

        free(arr);
    }

    fclose(fb);
    fclose(fw);
    fclose(fa);
}

/* Tester */
void Tester(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return;
    }
    int *arr = malloc(n * sizeof(int));
    if (!arr) { perror("malloc"); return; }

    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int comps = bubble_sort(arr, n);
    printf("After sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\nComparisons made: %d\n", comps);
    free(arr);
}

int main(void) {
    /* 1) Generate data files for plotting */
    plotter();

    /* 2) Run interactive demo */
    interactive_demo();

    return 0;
}
