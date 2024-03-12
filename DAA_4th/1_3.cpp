#include <iostream>
#include <vector>
using namespace std;
void jumpSearch(vector<int>& arr, int key) {
    int comp=0;
    if (arr[0]==key) {
        cout << "Present " <<++comp << endl;
        return;
    }
    int i=1;
    while (i<arr.size() && arr[i]<=key) {
        i*=2;
        comp++;
    }
    for (int j=i/2; j<i; j++) {
        if (arr[j]==key) {
            cout << "Present " << comp << endl;
            return;
        }
        comp++;
    }
    cout << "Not Present " << comp << endl;
}
int main() {
    int t, x, key, n;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-->0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i=0; i<n; i++) cin >> arr[i];
        cout << "Enter the key: ";
        cin >> key;
        jumpSearch(arr, key);
    }
}