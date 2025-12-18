#include <stdio.h>

int a[10][10], visited[10], n;
void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    dfs(1);
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT Connected\n");
            return 0;
        }
    }

    printf("Graph is Connected\n");
    return 0;
}

