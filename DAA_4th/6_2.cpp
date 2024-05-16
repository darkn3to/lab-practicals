#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int n, vector<vector<int>> &matrix) {
    vector<short> group(n, -1);
    queue<int> q;
    q.push(0);
    group[0] = 0;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        if (matrix[k][k])
            return false;
        for (int i = 0; i < n; i++) {
            if (matrix[k][i]) {
                if (group[i] == -1)
                    group[i] = !group[k], q.push(i);
                else if (group[i] == group[k])
                    return false;
            }
        }
    }
    return true;
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
        if (isBipartite(n, matrix))
            cout << "Yes Bipartite" << endl;
        else
            cout << "No Bipartite" << endl;
        cout << endl;
    }
    return 0;
}