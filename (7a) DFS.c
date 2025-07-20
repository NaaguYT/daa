#include <stdio.h>
#include <stdlib.h>

int orderCount = 0;
int isCyclic = 0;
int visitedCount = 0;
int graph[100][100], visited[100];

void dfs(int totalVertices, int currentVertex, int parentVertex) {
    visited[currentVertex] = 1;
    visitedCount++;
    printf("--> %c ", currentVertex + 65); // Debug output in letter format

    for (int neighbor = 0; neighbor < totalVertices; neighbor++) {
        orderCount++;
        if (neighbor != parentVertex && graph[currentVertex][neighbor] && visited[neighbor])
            isCyclic = 1;

        if (graph[currentVertex][neighbor] && visited[neighbor] == 0)
            dfs(totalVertices, neighbor, currentVertex);
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

    dfs(n, 0, -1);

    if (n == visitedCount)
        printf("\nThe graph is connected\n");
    else {
        printf("\nThe graph is not connected\n");

        for (int vertex = 1; vertex < n; vertex++) {
            if (!visited[vertex])
                dfs(n, vertex, -1);
        }
    }

    if (isCyclic)
        printf("\nThe graph is cyclic\n");
    else
        printf("\nThe graph is acyclic\n");
}

void plotter(int isBestCase) {
    FILE* bestFile = fopen("DFS_Best_Matrix.txt", "a");
    FILE* worstFile = fopen("DFS_Worst_Matrix.txt", "a");

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

        visitedCount = 0;
        orderCount = 0;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i])
                dfs(vertices, i, -1);
        }

        if (isBestCase)
            fprintf(bestFile, "%d\t%d\n", vertices, orderCount);
        else
            fprintf(worstFile, "%d\t%d\n", vertices, orderCount);
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
