#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int orderCount = 0;
int isCyclic = 0;
int visitedCount = 0;
int graph[MAX][MAX], visited[MAX];

void bfs(int totalVertices, int startVertex) {
    int queue[MAX], parent[MAX];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    visitedCount++;

    queue[++rear] = startVertex;
    parent[rear] = -1;

    while (front != rear) {
        startVertex = queue[++front];
        int parentNode = parent[front];

        // printf("--> %c ", startVertex + 65); // For testing traversal

        for (int neighbor = 0; neighbor < totalVertices; neighbor++) {
            orderCount++;

            if (graph[startVertex][neighbor]) {
                if (visited[neighbor]) {
                    if (neighbor != parentNode) {
                        isCyclic = 1;
                    }
                } else {
                    visited[neighbor] = 1;
                    visitedCount++;

                    queue[++rear] = neighbor;
                    parent[rear] = startVertex;
                }
            }
        }
    }
}

void tester() {
    int totalVertices;
    printf("Enter the number of vertices:\n");
    scanf("%d", &totalVertices);

    printf("Enter the adjacency matrix:\n");
    for (int row = 0; row < totalVertices; row++) {
        for (int col = 0; col < totalVertices; col++) {
            scanf("%d", &graph[row][col]);
        }
        visited[row] = 0;
    }

    printf("The adjacency matrix:\n");
    for (int row = 0; row < totalVertices; row++) {
        for (int col = 0; col < totalVertices; col++) {
            printf("%d ", graph[row][col]);
        }
        printf("\n");
    }

    isCyclic = 0;
    visitedCount = 0;

    bfs(totalVertices, 0);

    if (visitedCount == totalVertices) {
        printf("\nThe graph is connected\n");
    } else {
        printf("\nThe graph is not connected\n");

        for (int vertex = 1; vertex < totalVertices; vertex++) {
            if (!visited[vertex]) {
                bfs(totalVertices, vertex);
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

