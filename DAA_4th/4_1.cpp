#include <iostream>
#include <vector>
using namespace std;
void merges(vector<int> &nums, int l, int mid, int r, int &noc, int &noi) {
    int ls = mid - l + 1, rs = r - mid;
    vector<int> larr(ls), rarr(rs);
    for (int i = 0; i < ls; i++) larr[i] = nums[l + i];
    for (int i = 0; i < rs; i++) rarr[i] = nums[mid + i + 1];
    int i = 0, j = 0, k = l;
    while (i < ls && j < rs) {
        if (larr[i] <= rarr[j]) nums[k++] = larr[i++];
        else {
            nums[k++] = rarr[j++];
            noi += mid - i + 1;
        }
        noc++;
    }
    while (i < ls) nums[k++] = larr[i++];
    while (j < rs) nums[k++] = rarr[j++];
}
void mergeSort(vector<int> &nums, int l, int r, int &noc, int &noi) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid, noc, noi);
        mergeSort(nums, mid + 1, r, noc, noi);
        merges(nums, l, mid, r, noc, noi);
    }
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, noc = 0, noi = 0;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums[i];
        mergeSort(nums, 0, n - 1, noc, noi);
        for (int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << endl;
        cout << "comparisons = " << noc << endl;
        cout << "inversions = " << noi << endl;
        cout << endl;
    }
    return 0;
}