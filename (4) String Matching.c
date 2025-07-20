#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_LEN   1000
#define MIN_P      10
#define MAX_P      1000

int op_count;

int bf_match(char text[], char pat[], int n, int m) {
    op_count = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            op_count++;                 /* one comparison */
            if (pat[j] != text[i+j])
                break;
            j++;
        }
        if (j == m) {
            return 1;                   /* found */
        }
    }
    return 0;                           /* not found */
}
void plotter(void) {
    FILE *fb = fopen("str_best.txt",  "a");
    FILE *fw = fopen("str_worst.txt", "a");
    FILE *fa = fopen("str_avg.txt",   "a");

    char *text = malloc(1000*sizeof(char));
    for(int i=0;i<1000;i++)
       str[i]='a';
    srand(time(NULL));
    for (int i = 10; i <= 1000; i = (i < 100 ? i + 10 : i + 100)) {
        char *pat = malloc(i*sizeof(char));

        /* Best case: pattern of all 'a's */
        for (int j = 0; j < i; j++) pat[j] = 'a';
        bf_match(text, pat, TEXT_LEN, i);
        fprintf(fb, "%d\t%d\n", i, op_count);

        /* Worst case: last char mismatches to force full compare */
        for (int j = 0; j < i-1; j++) pat[j] = 'a';
        pat[i-1] = 'b';
        bf_match(text, pat, TEXT_LEN, i);
        fprintf(fw, "%d\t%d\n", i, op_count);

        /* Average case: random small alphabet {'a','b','c'} */
        for (int j = 0; j < i; j++) pat[j] = 'a' + (rand() % 3);
        bf_match(text, pat, TEXT_LEN, i);
        fprintf(fa, "%d\t%d\n", i, op_count);

        free(pat);
    }
    free(text);
    fclose(fb);
    fclose(fw);
    fclose(fa);
}

void tester(void) {
    char text[1001], pat[1001];
    printf("Enter text (no spaces): ");
    scanf("%1000s", text);
    printf("Enter pattern: ");
    scanf("%1000s", pat);

    int n = strlen(text), m = strlen(pat);
    op_count = 0;
    int found = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            op_count++;
            if (pat[j] != text[i+j]) break;
            j++;
        }
        if (j == m) { found = 1; break; }
    }
    if (found)
        printf("Pattern found (comparisons: %d)\n", op_count);
    else
        printf("Pattern not found (comparisons: %d)\n", op_count);
}

int main(void) {
    plotter();
    tester();
    return 0;
}
