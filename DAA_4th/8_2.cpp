//
// Created by Manas Singh on 17-05-2024.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void kruskal(vector<Edge>& edges, int n) {
    vector<int> tree_id;
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);
            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id) tree_id[i] = new_id;
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
        cout << "Minimum Spanning Weight: " << kruskal(n, matrix) << endl;
        cout << endl;
    }
    return 0;
}