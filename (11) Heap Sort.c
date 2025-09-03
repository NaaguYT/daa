#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;

void swap(int *a,int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int arr[],int n,int i) {
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if (left <= n) {
    	count++;
    	if (arr[largest] < arr[left])
        	largest = left;
    }
    if (right <= n) {
       count++;
    	if(arr[largest] < arr[right])
        	largest = right;
    }
    if(largest!=i) {
        swap(&arr[largest],&arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[],int n) {
    for(int i = n/2; i >= 1; i--) {
    	heapify(arr, n, i);
    }
    int size=n;
    while(size>1) {
        swap(&arr[1],&arr[size]);
        //largest element is at last
        size--;
        heapify(arr,size,1);

    }
}

void tester() {
	int n;
	printf("\nEnter the number of elements\n");
	scanf("%d",&n);
	int arr[n+1];
	printf("\nEnter the elements\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	printf("\nThe elements of the array before sorting\n");
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	heapsort(arr,n);
	printf("\nThe elements of the array after sorting\n");
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void plotter() {
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3;

    f1 = fopen("HEAPSORTBEST.txt", "w");
    f2 = fopen("HEAPSORTWORST.txt", "w");
    f3 = fopen("HEAPSORTAVG.txt", "w");

    n = 100;

    while (n <= 1000) {
        // Best Case
        arr = (int *)malloc(sizeof(int) * (n + 1));
        for (int i = 1; i <= n; i++)
            arr[i] = n - i + 1;

        count = 0;
        heapsort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst Case
        for (int i = 1; i <= n; i++)
            arr[i] = i;

        count = 0;
        heapsort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // Avg Case
        for (int i = 1; i <= n; i++)
            arr[i] = rand() % n;

        count = 0;
        heapsort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        n = n + 100;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int choice;
    do {
        printf("1. Tester\n2. Plotter\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tester();
                break;
            case 2:
                plotter();
                break;
            case 0:
                printf("Exited from the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

	return 0;
}
