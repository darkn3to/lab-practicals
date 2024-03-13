#include <iostream>
#include <vector>
using namespace std;
void selection_sort(vector<int>& v) {
    int n=v.size();
    int swaps=0, comparisons=0;
    for(int i=0; i<n-1; i++) {
        int min_idx=i;
        for(int j=i+1; j<n; j++) {
            if(v[j]<v[min_idx]) min_idx=j;
            ++comparisons;
        }
        swap(v[min_idx], v[i]);
        if(min_idx!=i) ++swaps; 
    }
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << v[i] << " ";
    cout << endl << "Comparisons: " << comparisons << endl << "Swaps: " << swaps << endl;
}
int main() {
    int t, n;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t-->0) {
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements: ";
        for(int i=0;i<n;i++) cin >> arr[i];
        selection_sort(arr);
    }
}