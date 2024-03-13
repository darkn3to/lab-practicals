#include <iostream>
#include <vector>
using namespace std;
void insertion_sort(vector<int>& v) {
    int n=v.size(), shifts=0, comparisons=0;
    for(int i=1; i<n; i++) {
        int key=v[i], j=i-1;
        while(j>=0&&v[j]>key) {
            v[j+1]=v[j];
            j=j-1;
            ++shifts;
            ++comparisons;
        }
        v[j+1]=key;
        if(j>=0) ++comparisons; 
    }
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << v[i] << " ";
    cout << endl << "Comparisons: " << comparisons << endl << "Shifts: " << shifts << endl;
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
        for(int i=0;i<n;i++) cin >> arr[i];
        insertion_sort(arr);
    }
}