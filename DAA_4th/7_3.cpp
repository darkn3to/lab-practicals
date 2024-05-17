//
// Created by Manas Singh on 16-05-2024.
//
#include <iostream>
#include <vector>

using namespace std;

int findPathKEdges(int n, vector<vector<int>> &matrix, int source, int destination, int k) {
    vector<vector<int>> distance(2, vector<int>(n, INT_MAX));
    distance[0][source] = 0;
    for (int l = 1; l <= k; l++) {
        fill(distance[l % 2].begin(), distance[l % 2].end(), INT_MAX);
        for (int i = 0; i < n; i++)
            if (distance[!(l % 2)][i] != INT_MAX)
                for (int j = 0; j < n; j++)
                    if (matrix[i][j]) {
                        distance[l % 2][j] = min(distance[l % 2][j], distance[!(l % 2)][i] + matrix[i][j]);
                    }
    }
    return (distance[k % 2][destination] == INT_MAX) ? -1 : distance[k % 2][destination];
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, source, destination, k;
        cout << "Enter number of nodes: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Enter adjacency matrix: " << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        cout << "Enter Source and Destination: ";
        cin >> source >> destination;
        cout << "Enter k: ";
        cin >> k;
        int shortestPath = findPathKEdges(n, matrix, source - 1, destination - 1, k);
        if (shortestPath == -1)
            cout << "no path of length k is available" << endl;
        else
            cout << "Weight of shortest path from (" << source << "," << destination << ") with " << k << " edges : "
                 << shortestPath << endl;
        cout << endl;
    }
    return 0;
}