#include <iostream>
using namespace std;

void DFS(int graph[10][10], int nodes, int start) {
    int stack[10];
    int top = -1;
    int visited[10] = {0};
    stack[++top] = start;

    cout<<"DFS Traversal: ";
    while (top!= -1) {
        int current = stack[top--];
        if (visited[current] == 0) {
            cout<<current<< " ";
            visited[current] = 1;

            for (int i = 0; i < nodes; i++) {
                if (graph[current][i] ==1 && visited[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes = 9;
    int graph[10][10] = {0};
    graph[5][2] = 1; graph[5][0] = 1; graph[2][4] = 1; graph[2][7] = 1;
    graph[7][5] = 1; graph[7][6] = 1; graph[7][8] = 1; graph[6][3] = 1;
    graph[6][5] = 1; graph[6][8] = 1; graph[3][1] = 1; graph[1][0] = 1;

    DFS(graph, nodes, 5);
    return 0;
}

