#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool contains_duplicates(vector<int>& v) {
    sort(v.begin(), v.end());
    for(int i=0; i<v.size()-1; i++) {
        if(v[i]==v[i+1]) return true;
    }
    return false;
}
int main() {
    int t,n;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t-->0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements: ";
        for(int i=0; i<n; i++) cin >> arr[i];
        if(contains_duplicates(arr)) cout << "YES " << endl;
        else cout << "NO " << endl;
    }
}
