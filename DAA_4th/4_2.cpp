#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int part(vector<int> &nums, int l, int r, int &noc, int &nos) {
    int pivot = l + rand() % (r - l + 1);
    if (pivot != r) swap(nums[pivot], nums[r]), nos++;
    pivot = l - 1;
    while (l < r) {
        noc++;
        if (nums[l] < nums[r]) {
            pivot++;
            if (pivot != l) swap(nums[pivot], nums[l]), nos++;
        }
        l++;
    }
    if (++pivot != r) swap(nums[pivot], nums[r]), nos++;
    return pivot;
}
void randomQuickSort(vector<int> &nums, int l, int r, int &noc, int &nos) {
    if (l < r) {
        int pivot = part(nums, l, r, noc, nos);
        randomQuickSort(nums, l, pivot - 1, noc, nos);
        randomQuickSort(nums, pivot + 1, r, noc, nos);
    }
}
int main() {
    srand((unsigned)time(nullptr));
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, noc = 0, nos = 0;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums[i];
        randomQuickSort(nums, 0, n - 1, noc, nos);
        for (int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << endl;
        cout << "comparisons = " << noc << endl;
        cout << "swaps = " << nos << endl;
        cout << endl;
    }
    return 0;
}