#include <iostream>
using namespace std;

void BFS (int graph[10][10], int nodes, int start) {
    bool visited[10] = {false};
    int queue[10];
    int front = 0, rear = 0;

    visited[start]=true;
    queue[rear++]=start;
    cout<<"BFS: ";

    while (front!=rear) {
        int current = queue[front++];
        cout<<current<< " ";

        for (int i = 0; i<nodes; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout<<endl;
}
int main() {
    int nodes = 9;
    int graph[10][10] = {0};

    graph[5][2] = 1; graph[5][0] = 1;
    graph[2][4] = 1; graph[2][7] = 1;
    graph[7][5] = 1; graph[7][6] = 1;
    graph[7][8] = 1; graph[6][3] = 1;
    graph[6][5] = 1; graph[6][8] = 1;
    graph[3][1] = 1; graph[1][0] = 1;
    BFS(graph, nodes, 5);
    return 0;
}

//5 2 7 6 3 1 0 8 4
