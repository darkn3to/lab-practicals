#include <iostream>
#include <vector>
using namespace std;
void search(vector<int>& v, int key) {
    int comp=0, f=0;
    for (auto it:v) {
        if (it==key) {
            f=1; break;
        }
        ++comp;
    }
    if (f==1) cout << "Present " << comp+1 << endl;
    else cout << "Not Present " << comp << endl;
}
int main() {
    int t, key, n;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-->0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements: ";
        for (int i=0; i<n; i++) cin >> arr[i];
        cout << "Enter the target: ";
        cin >> key;
        search(arr, key);
    }
}