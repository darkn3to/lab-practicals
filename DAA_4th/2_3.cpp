#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countPair(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int l = 0, r = 0, n = nums.size(), c = 0;
    while (r < n) {
        if (nums[r] - nums[l] == target) {
            int i = 1, j = 1;
            while (l < n - 1 && nums[l] == nums[l + 1]) l++, i++;
            while (r < n - 1 && nums[r] == nums[r + 1]) r++, j++;
            c += (i * j);
            l++, r++;
        }
        else if (nums[r] - nums[l] < target) r++;
        else l++;
    }
    return c;
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, target;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << "Enter the key: ";
        cin >> target;
        cout << countPair(nums, target) << endl;
        cout << endl;
    }
    return 0;
}