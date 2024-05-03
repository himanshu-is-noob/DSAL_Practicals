#include<iostream>
#include<stdlib.h>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front = 0, rear = 0, v, visit[10], visited[10];
int stk[10], top = 0, visit1[10], visited1[10];

int main() {
    int m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "\nEDGES \n";
    for (k = 1; k <= m; k++) {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    // Display adjacency matrix
    cout << "The adjacency matrix of the graph is:" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    cout << "Enter initial vertex for BFS: ";
    cin >> v;
    cout << "The BFS of the Graph is\n";
    cout << v;
    visited[v] = 1;
    k = 1;
    qu[rear++] = v;
    while (front != rear) {
        v = qu[front++];
        for (j = 1; j <= n; j++) {
            if (cost[v][j] != 0 && visited[j] != 1) {
                qu[rear++] = j;
                cout << " " << j;
                visited[j] = 1;
            }
        }
    }

    cout << "\nEnter initial vertex for DFS: ";
    cin >> v;
    cout << "The DFS of the Graph is\n";
    cout << v;
    visited1[v] = 1;
    k = 1;
    stk[top++] = v;
    while (top != 0) {
        v = stk[--top];
        for (j = 1; j <= n; j++) {
            if (cost[v][j] != 0 && visited1[j] != 1) {
                cout << " " << j;
                visited1[j] = 1;
                stk[top++] = j;
            }
        }
    }

    return 0;
}
