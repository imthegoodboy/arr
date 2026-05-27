#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    char pattern[50];

    int i, j;
    int n, m;
    int found = 0;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    // Brute force matching
    for(i = 0; i <= n - m; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
            {
                break;
            }
        }

        // Pattern found
        if(j == m)
        {
            printf("Pattern found at position %d\n", i + 1);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Pattern not found\n");
    }

    return 0;
} 














#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j;
    int arr[20000];
    int duplicate = 0;

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

    // Check for duplicates
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }

        if(duplicate == 1)
        {
            break;
        }
    }

    // End time
    end = clock();

    double time_taken;
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(duplicate == 1)
    {
        printf("Duplicate elements found.\n");
    }
    else
    {
        printf("All elements are unique.\n");
    }

    printf("Time taken = %f seconds\n", time_taken);

    return 0;
}





















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


















Dijkstra’s Algorithm.

#include <stdio.h>

#define MAX 100
#define INF 99999

int main() {
    int graph[MAX][MAX], n, source;
    int distance[MAX], visited[MAX];
    int i, j, min, u;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            // Replace 0 with INF except diagonal
            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    // Input source vertex
    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distance and visited arrays
    for(i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    // Dijkstra's Algorithm
    for(i = 0; i < n - 1; i++) {

        min = INF;

        // Find nearest unvisited vertex
        for(j = 0; j < n; j++) {
            if(!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update shortest distances
        for(j = 0; j < n; j++) {
            if(!visited[j] &&
               distance[u] + graph[u][j] < distance[j]) {

                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, distance[i]);
    }

    return 0;
}









Topological Sort (Kahn’s Algorithm).

#include <stdio.h>

#define MAX 100

int main() {
    int n, graph[MAX][MAX];
    int indegree[MAX] = {0};
    int visited[MAX] = {0};
    int i, j, count = 0;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            // Calculate indegree
            if(graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("\nTopological Ordering:\n");

    // Find vertices with indegree 0
    while(count < n) {

        for(i = 0; i < n; i++) {

            if(indegree[i] == 0 && !visited[i]) {

                // Print vertex
                printf("%d ", i);

                visited[i] = 1;
                count++;

                // Reduce indegree of adjacent vertices
                for(j = 0; j < n; j++) {
                    if(graph[i][j] == 1) {
                        indegree[j]--;
                    }
                }
            }
        }
    }

    printf("\n");

    return 0;
}













0/1 Knapsack Problem using the Dynamic Programming method.

#include <stdio.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    int n, i, j, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    // Input weights
    printf("Enter weights of items:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    // Input profits
    printf("Enter profits of items:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    // Input knapsack capacity
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    // Build DP table
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= capacity; j++) {

            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(weight[i - 1] <= j) {

                dp[i][j] = max(
                    profit[i - 1] + dp[i - 1][j - weight[i - 1]],
                    dp[i - 1][j]
                );
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print maximum profit
    printf("\nMaximum Profit = %d\n", dp[n][capacity]);

    return 0;
}














subset of a given set whose sum is equal to a given value using the Backtracking method.

#include <stdio.h>

int set[100], subset[100];
int n, target, found = 0;

// Function to find subsets
void subsetSum(int sum, int k, int remaining) {

    int i;

    // If target sum is achieved
    if(sum == target) {

        found = 1;

        printf("Subset found: ");

        for(i = 0; i < k; i++) {
            if(subset[i] == 1) {
                printf("%d ", set[i]);
            }
        }

        printf("\n");
        return;
    }

    // Generate further subsets
    for(i = k; i < n; i++) {

        if(sum + set[i] <= target) {

            subset[i] = 1;

            subsetSum(sum + set[i], i + 1,
                      remaining - set[i]);

            subset[i] = 0;
        }
    }
}

int main() {

    int i, total = 0;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input set elements
    printf("Enter elements of the set:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &set[i]);
        total += set[i];
    }

    // Input target sum
    printf("Enter target sum: ");
    scanf("%d", &target);

    // Check possibility
    if(target > total) {
        printf("No subset possible.\n");
        return 0;
    }

    // Initialize subset array
    for(i = 0; i < n; i++) {
        subset[i] = 0;
    }

    // Find subsets
    subsetSum(0, 0, total);

    if(!found) {
        printf("No subset found.\n");
    }

    return 0;
}


























The N-Queens problem places N queens on an N × N chessboard such that no two queens attack each other.

#include <stdio.h>
#include <stdlib.h>

int board[20], count = 0;

// Function to check whether queen can be placed
int isSafe(int row, int col) {

    int i;

    for(i = 1; i < row; i++) {

        // Check same column or diagonal attack
        if(board[i] == col ||
           abs(board[i] - col) == abs(i - row)) {

            return 0;
        }
    }

    return 1;
}

// Function to solve N-Queens problem
void solve(int row, int n) {

    int col, i, j;

    // If all queens are placed
    if(row > n) {

        count++;

        printf("\nSolution %d:\n\n", count);

        for(i = 1; i <= n; i++) {

            for(j = 1; j <= n; j++) {

                if(board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }

            printf("\n");
        }

        return;
    }

    // Try placing queen in each column
    for(col = 1; col <= n; col++) {

        if(isSafe(row, col)) {

            board[row] = col;

            solve(row + 1, n);
        }
    }
}

int main() {

    int n;

    // Input number of queens
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(1, n);

    if(count == 0) {
        printf("No solutions found.\n");
    }

    return 0;
}













 
