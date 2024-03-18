#include <iostream>
#include <vector>
using namespace std;
bool kthSmallest(vector<int> &nums, int k) {
    int l = nums[0], r = nums[0];
    for (auto &i : nums) l = min(i, l), r = max(i, r);
    r -= l - 1;
    vector<int> freq(r);
    for (auto &i : nums) freq[i - l]++;
    for (int i = 0; i < r; i++) {
        if (freq[i]) k--;
        if (k == 0) {
            cout << i + l << endl;
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << "Enter k: ";
        cin >> k;
        if (!kthSmallest(nums, k)) cout << "not present" << endl;
        cout << endl;
    }
    return 0;
}