#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkInversion()
{

}

void mergeSort(vector<int> &nums, int l, int r, int &noc, int &noi)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        if (checkInversion(nums, l, mid)!=0)
            mergeSort(nums, l, mid, noc, noi);
        if (checkInversion(nums, mid + 1, r))
            mergeSort(nums, mid + 1, r, noc, noi);
        merges(nums, l, mid, r, noc);
    }
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0)
    {
        int n, noc = 0, noi = 0;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        mergeSort(nums, 0, n - 1, noc, noi);
        for (int i = 0; i < n; i++)
            cout << nums[i];
        cout << endl;
        cout << "comparisons = " << noc << endl;
        cout << "inversions = " << noi << endl;
        cout << endl;
    }
    return 0;
}