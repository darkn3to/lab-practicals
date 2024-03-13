#include <iostream>
#include <vector>
using namespace std;
void binarySearch(vector<int>& v, int key) {
    int left=0, right=v.size()-1, comp=0;
    bool found=false;
    while (left<=right) {
        ++comp;
        int mid=left+(right-left)/2;
        if (v[mid]==key) {
            found=true;
            break;
        }
        else if (v[mid] < key) left=mid+1;
        else right=mid-1;
    }
    if (found) cout << "Present " << comp << endl;
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
        binarySearch(arr, key);
    }
}