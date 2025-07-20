#include <stdio.h>
#include <stdlib.h>

int orderCount = 0;
int isCyclic = 0;
int visitedCount = 0;
int graph[100][100], visited[100];

void bfs(int n, int startVertex) {
    int queue[100], parent[100];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    visitedCount++;

    queue[++rear] = startVertex;
    parent[rear] = -1;

    while (front != rear) {
        startVertex = queue[++front];
        int parentNode = parent[front];

        // printf("--> %c ", startVertex + 65); // For testing traversal

        for (int i = 0; i < n; i++) {
            orderCount++;

            if (graph[startVertex][i]) {
                if (visited[i]) {
                    if (i != parentNode) {
                        isCyclic = 1;
                    }
                } else {
                    visited[i] = 1;
                    visitedCount++;

                    queue[++rear] = i;
                    parent[rear] = startVertex;
                }
            }
        }
    }
}

void tester() {
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            scanf("%d", &graph[row][col]);
        }
        visited[row] = 0;
    }

    printf("The adjacency matrix:\n");
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d ", graph[row][col]);
        }
        printf("\n");
    }

    isCyclic = 0;
    visitedCount = 0;

    bfs(n, 0);

    if (visitedCount == n) {
        printf("\nThe graph is connected\n");
    } else {
        printf("\nThe graph is not connected\n");

        for (int vertex = 1; vertex < n; vertex++) {
            if (!visited[vertex]) {
                bfs(n, vertex);
            }
        }
    }

    if (isCyclic)
        printf("\nThe graph is cyclic\n");
    else
        printf("\nThe graph is acyclic\n");
}

void plotter(int isBestCase) {
    FILE *bestFile = fopen("BFS_Best.txt", "a");
    FILE *worstFile = fopen("BFS_Worst.txt", "a");

    for (int vertices = 1; vertices <= 10; vertices++) {
        // Reset graph
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                graph[i][j] = 0;
        }

        if (!isBestCase) {  // Worst case (Dense Graph)
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (i != j)
                        graph[i][j] = 1;
                }
            }
        } else {  // Best case (Linear Chain)
            for (int i = 0; i < vertices - 1; i++) {
                graph[i][i + 1] = 1;
            }
        }

        for (int i = 0; i < vertices; i++)
            visited[i] = 0;

        orderCount = 0;
        visitedCount = 0;

        bfs(vertices, 0);

        if (isBestCase == 0)
            fprintf(worstFile, "%d\t%d\n", vertices, orderCount);
        else
            fprintf(bestFile, "%d\t%d\n", vertices, orderCount);
    }

    fclose(bestFile);
    fclose(worstFile);
}

int main() {
    while (1) {
        int choice;
        printf("Enter your choice:\n1. To Test\n2. To Plot\nOther to Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tester();
                break;
            case 2:
                for (int caseType = 0; caseType < 2; caseType++)
                    plotter(caseType);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}

