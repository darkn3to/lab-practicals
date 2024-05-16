//
// Created by Manas Singh on 16-05-2024.
//
#include <iostream>
#include <vector>

using namespace std;

bool helper(int n, vector<vector<int>> &matrix, vector<bool> &visited, int curr) {
    if (visited[curr])
        return true;
    visited[curr] = true;
    for (int i = 0; i < n; i++) {
        if (matrix[curr][i] && helper(n, matrix, visited, i))
            return true;
    }
    visited[curr] = false;
    return false;
}

bool cycleExists(int n, vector<vector<int>> &matrix) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (helper(n, matrix, visited, i))
            return true;
    }
    return false;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Enter adjacency matrix: " << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        if (cycleExists(n, matrix))
            cout << "Yes Cycle Exists" << endl;
        else
            cout << "No Cycle Exists" << endl;
        cout << endl;
    }
    return 0;
}