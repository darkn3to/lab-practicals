//
// Created by Manas Singh on 16-05-2024.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int n, vector<vector<int>> &matrix, vector<int> &distance, vector<int> &parent, int source) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distance[source] = 0;
    pq.emplace(0, source);
    while (!pq.empty()) {
        int curr = pq.top().second;
        visited[curr] = true;
        pq.pop();
        for (int i = 0; i < n; i++)
            if (matrix[curr][i] && !visited[i] && distance[curr] + matrix[curr][i] < distance[i]) {
                distance[i] = matrix[curr][i] + distance[curr];
                parent[i] = curr;
                pq.emplace(distance[i], i);
            }
    }
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, source;
        cout << "Enter number of nodes: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Enter adjacency matrix: " << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        cout << "Enter meeting node: ";
        cin >> source;
        vector<int> distance(n, INT_MAX);
        vector<int> parent(n, -1);
        dijkstra(n, matrix, distance, parent, source);
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j != -1) {
                cout << j << " ";
                j = parent[j];
            }
            cout << ": " << distance[i] << endl;
        }
        cout << endl;
    }
    return 0;
}