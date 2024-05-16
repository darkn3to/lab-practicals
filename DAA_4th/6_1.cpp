#include <iostream>
#include <vector>
using namespace std;
bool helper(int n, vector<vector<int>> &matrix, vector<bool> &visited, int curr, int destination)
{
    if (curr == destination)
        return true;
    visited[curr] = true;
    for (int i = 0; i < n; i++)
        if (!visited[i] && matrix[curr][i] && helper(n, matrix, visited, i, destination))
            return true;
    return false;
}
bool dfs(int n, vector<vector<int>> &matrix, int source, int destination)
{
    vector<bool> visited(n);
    return helper(n, matrix, visited, source, destination);
}
int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0)
    {
        int n, source, destination;
        cout << "Enter number of nodes: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Enter adjacency matrix: " << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        cout << "Enter the source: ";
        cin >> source;
        cout << "Enter the destination: ";
        cin >> destination;
        if (dfs(n, matrix, source - 1, destination - 1))
            cout << "Yes Path Exists" << endl;
        else
            cout << "No Such Path Exists" << endl;
        cout << endl;
    }
    return 0;
}