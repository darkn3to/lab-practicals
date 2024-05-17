//
// Created by Manas Singh on 16-05-2024.
//

#include <iostream>
#include <vector>

using namespace std;

void bellmanFord(int n, vector<vector<int>> &matrix, vector<int> &distance, vector<int> &parent, int source) {
    distance[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[j] != INT_MAX)
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] > 0 && distance[j] + matrix[j][k] < distance[k]) {
                        distance[k] = distance[j] + matrix[j][k];
                        parent[k] = j;
                    }
                }
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
        bellmanFord(n, matrix, distance, parent, source - 1);
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j != -1) {
                cout << j + 1 << " ";
                j = parent[j];
            }
            cout << ": " << distance[i] << endl;
        }
        cout << endl;
    }
    return 0;
}