#include <iostream>
#include <vector>
using namespace std;
int frequencySearch(vector<int> nums, int target) {
    int n=nums.size();
    int l=0, r=n-1, l1=-1, r1=-1;
    while (l<=r) {
        int mid=(l+r)/2;
        if (nums[mid]==target && (mid==0 || nums[mid-1]!=target)) {
            l1=mid; break;
        }
        if (nums[mid]>=target) r=mid-1;
        else l=mid+1;
    }
    if (l1==-1) return 0;
    l=l1, r=n-1;
    while (l<=r) {
        int mid=(l+r)/2;
        if (nums[mid]==target && (mid==n-1 || nums[mid+1]!=target)) {
            r1=mid; break;
        }
        if (nums[mid]<=target) l=mid+1;
        else r=mid-1;
    }
    return r1-l1+1;
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-->0) {
        int n, target;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i=0; i < n; i++) cin >> nums[i];
        cout << "Enter the target: ";
        cin >> target;
        cout << target << " - " << frequencySearch(nums, target) << endl;
        cout << endl;
    }
    return 0;
}