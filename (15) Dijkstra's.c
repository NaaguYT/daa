#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int graph[40][40], visit[40], dist[40];
int cnt, n;

void CreateGraph(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : rand() % 100 + 1;
        }
    }
}

void dijkstra(int v) {
    int i, w, u = 0, min;

    for (i = 1; i <= n; i++) {
        visit[i] = 0;
        dist[i] = graph[v][i];
    }

    visit[v] = 1;
    dist[v] = 0;

    for (int num = 2; num <= n; num++) {
        min = 9999;
        for (w = 1; w <= n; w++) {
            cnt++;
            if (!visit[w] && dist[w] < min) {
                min = dist[w];
                u = w;
            }
        }

        if (u == 0 && n > 1) {
            break;
        }

        visit[u] = 1;

        for (w = 1; w <= n; w++) {
            cnt++;
            if (!visit[w]) {
                if (dist[w] > dist[u] + graph[u][w]) {
                    dist[w] = dist[u] + graph[u][w];
                }
            }
        }
    }
}

void tester() {
    int v;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    printf("Enter 999 if the edge is not present or for self loops.\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex:\n");
    scanf("%d", &v);
    cnt = 0;
    dijkstra(v);

    printf("VERTEX\tDESTINATION\tCOST\n");
    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\n", v, i, dist[i]);
    }

    printf("count: %d\n", cnt);
}

void plotter() {
    FILE *fp;
    fp = fopen("dijkstra_gen.txt", "w");
    srand(time(0));

    for (n = 2; n < 12; n++) {
        cnt = 0;
        CreateGraph(n);
        dijkstra(1);
        fprintf(fp, "%d\t%d\n", n, cnt);
    }

    fclose(fp);
}

void main() {
    int ch;
    for (;;) {
        printf("\nEnter:\n1.Tester\n2.Plotter\nOther to exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: tester();
                    break;
            case 2: plotter();
                    break;
            default: exit(1);
        }
    }
}
