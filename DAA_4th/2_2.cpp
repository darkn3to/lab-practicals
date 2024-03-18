#include <iostream>
#include <vector>
using namespace std;
bool searchTriplet(vector<int> &nums) {
    int n = nums.size();
    for (int k = n - 1; k > 1; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == nums[k]) {
                cout << i + 1 << ", " << j + 1 << ", " << k + 1 << endl;
                return true;
            }
            else if (sum < nums[k]) i++;
            else j--;
        }
    }
    return false;
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums[i];
        if (!searchTriplet(nums)) cout << "No sequence found." << endl;
        cout << endl;
    }
    return 0;
}