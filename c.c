 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main() {

    int n, i;
    int arr[20000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Generate random numbers
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start, end;

    start = clock();

    quicksort(arr, 0, n - 1);

    end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Array sorted successfully.\n");

    printf("Time taken = %f seconds\n", time_taken);

    return 0;
}

void quicksort(int arr[], int low, int high) {

    if(low < high) {

        int p = partition(arr, low, high);

        quicksort(arr, low, p - 1);

        quicksort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high) {

    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while(i <= j) {

        while(arr[i] <= pivot && i <= high)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);

    return j;
}

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}







## merge short 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main()
{
    int n, i;
    int arr[20000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Generate random numbers
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }

    clock_t start, end;

    // Start time
    start = clock();

    // Call Merge Sort
    mergesort(arr, 0, n - 1);

    // End time
    end = clock();

    // Calculate time taken
    double time_taken;
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Array sorted successfully.\n");

    printf("Time taken = %f seconds\n", time_taken);

    return 0;
}

// Merge Sort Function
void mergesort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        // Sort left half
        mergesort(arr, low, mid);

        // Sort right half
        mergesort(arr, mid + 1, high);

        // Merge both halves
        merge(arr, low, mid, high);
    }
}

// Merge Function
void merge(int arr[], int low, int mid, int high)
{
    int temp[20000];

    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}











#include <stdio.h>

#define MAX 20

int parent[MAX];

// Function to find parent
int find(int i)
{
    while(parent[i])
        i = parent[i];

    return i;
}

// Function to perform union
void uni(int i, int j)
{
    parent[j] = i;
}

int main()
{
    int n, i, j, a, b, u, v;
    int min, mincost = 0;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with large value
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    int edges = 1;

    while(edges < n)
    {
        min = 999;

        // Find minimum edge
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];

                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find parents
        u = find(u);
        v = find(v);

        // If no cycle
        if(u != v)
        {
            printf("%d Edge (%d,%d) = %d\n",
                   edges, a, b, min);

            mincost = mincost + min;

            uni(u, v);

            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}














#include <stdio.h>

#define MAX 20

int main()
{
    int cost[MAX][MAX];
    int visited[MAX];

    int n, i, j;
    int min, mincost = 0;
    int a, b, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    // Read matrix
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with large value
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    // Initialize visited array
    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    int edges = 1;

    while(edges < n)
    {
        min = 999;

        // Find minimum edge
        for(i = 1; i <= n; i++)
        {
            if(visited[i] == 1)
            {
                for(j = 1; j <= n; j++)
                {
                    if(visited[j] == 0)
                    {
                        if(cost[i][j] < min)
                        {
                            min = cost[i][j];

                            a = u = i;
                            b = v = j;
                        }
                    }
                }
            }
        }

        // Add edge to MST
        printf("%d Edge (%d,%d) = %d\n",
               edges, a, b, min);

        mincost = mincost + min;

        visited[b] = 1;

        edges++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}




 
