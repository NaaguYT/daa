#include <stdio.h>
#include <stdlib.h>

int op_count;

/* Sequential (linear) search: returns number of comparisons made */
int linear_search(int arr[], int n, int key) {
    op_count = 0;
    for (int i = 0; i < n; ++i) {
        op_count++;
        if (arr[i] == key) {
            return op_count;
        }
    }
    return op_count;
}

/* Plotter: writes best-case and worst-case data to separate files */
void plotter(void) {
    FILE *f_best = fopen("linsearch_best.txt", "w");
    FILE *f_worst = fopen("linsearch_worst.txt", "w");
    if (!f_best || !f_worst) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));

    for (int n = 10; n <= 100; n += 10) {
        int *arr = malloc(n * sizeof(int));
        if (!arr) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        /* Fill with random values 0..n-1 */
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % n;
        }

        /* Best case: key at position 0 */
        int best_key = arr[0];
        linear_search(arr, n, best_key);
        fprintf(f_best, "%d\t%d\n", n, op_count);

        /* Worst case: key not present (choose -1) */
        int worst_key = -1;
        linear_search(arr, n, worst_key);
        fprintf(f_worst, "%d\t%d\n", n, op_count);

        free(arr);
    }

    fclose(f_best);
    fclose(f_worst);
}

int main(void) {
    /* 1. Run the plotter to generate data files */
    plotter();
    /* 2. Optionally, perform an tester */
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("malloc");
        return 1;
    }
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int comps = linear_search(arr, n, key);
    if (comps < n) {
        printf("Key found in %d comparisons.\n", comps);
    } else {
        printf("Key not found after %d comparisons.\n", comps);
    }
    free(arr);
    return 0;
}
