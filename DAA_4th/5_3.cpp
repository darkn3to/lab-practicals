#include <iostream>
#include <vector>
using namespace std;
vector<int> findCommon(vector<int> &nums1, vector<int> &nums2) {
    int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
    vector<int> common;
    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) common.push_back(nums1[i++]), j++;
        else if (nums1[i] < nums2[j]) i++;
        else j++;
    }
    return common;
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n;
        cout << "Enter the number of elements in array1: ";
        cin >> n;
        vector<int> nums1(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums1[i];
        cout << "Enter the number of elements in array2: ";
        cin >> n;
        vector<int> nums2(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) cin >> nums2[i];
        vector<int> common = findCommon(nums1, nums2);
        cout << "Common elements: ";
        for (int &i : common) cout << i << " ";
        cout << "\n\n";
    }
    return 0;
}