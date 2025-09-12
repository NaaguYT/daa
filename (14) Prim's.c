#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void prims()
{
    int i, j, edges = 0;
    int a, b, min, min_cost = 0;
    int cost[50][50], n, visited[50] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

	count = 0;
    visited[0] = 1;

    while (edges < n - 1)
    {
        min = 9999;
        count++;
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    count++;
                    if (min > cost[i][j] && !visited[j])
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

		if (a == -1 || b == -1)
        {
            printf("Graph is disconnected! MST not possible.\n");
            fprintf(fp, "%d\tDisconnected\n", n);
            fclose(fp);
            return;
        }

        printf("%c --> %c | Cost: %d\n", a + 65, b + 65, min);
        visited[b] = 1;
        min_cost += min;
        edges++;
    }

    printf("Minimum Cost: %d\n", min_cost);
    printf("The count for the %d number of vertices is %d\n", n, count);

    fprintf(fp, "%d\t%d\n", n, count);
}

int main()
{
    srand(time(NULL));
    FILE *fp;
    fp = fopen("prims.txt", "a");
	int choice;
	for(;;)
	{
		printf("\nEnter the choice:\n1.To Execute\nother to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:prims();
			       break;
			default:exit(1);

		}
	}
    fclose(fp);
	return 0;
}

/*output
Enter the number of vertices: 5
Enter cost matrix:
0 0 3 0 0
0 0 10 4 0
3 10 0 2 6
0 4 2 0 1
0 0 6 1 0
A --> C | Cost: 3
C --> D | Cost: 2
D --> E | Cost: 1
D --> B | Cost: 4
Minimum Cost: 10
The count for the 5 number of vertices is 24
*/
