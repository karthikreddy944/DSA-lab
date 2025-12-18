#include <stdio.h>

int a[10][10], visited[10], n, queue[10], front = -1, rear = -1;

// Function to insert element into queue
void enqueue(int v) {
    queue[++rear] = v;
}

// Function to delete element from queue
int dequeue() {
    return queue[++front];
}

// BFS traversal
void bfs(int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != rear) {
        start = dequeue();
        printf("%d ", start);

        for (i = 1; i <= n; i++) {
            if (a[start][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
