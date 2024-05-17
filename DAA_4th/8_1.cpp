//
// Created by Manas Singh on 17-05-2024.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int prims(int n, vector<vector<int>> &matrix, int source) {
    int res = 0;
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source);
    while (!pq.empty()) {
        pair<int, int> temp = pq.top();
        pq.pop();
        if (inMST[temp.second])
            continue;
        res += temp.first;
        inMST[temp.second] = true;
        for (int i = 0; i < n; i++)
            if (!inMST[i] && matrix[temp.second][i])
                pq.emplace(matrix[temp.second][i], i);
    }
    return res;
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
        cout << "Minimum Spanning Weight: " << prims(n, matrix, 0) << endl;
        cout << endl;
    }
    return 0;
}