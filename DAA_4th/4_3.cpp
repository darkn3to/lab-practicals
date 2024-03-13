#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> arr[], int n, int i)
{
    int m = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[m])
        m = l;
    if (r < n && arr[r] < arr[m])
        m = r;
    if (m != i)
    {
        swap(arr[i], arr[m]);
        heapify(arr, n, m);
    }
}
void buildHeap(int arr[], int N)
{
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
}

bool kthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << "Enter k: ";
        cin >> k;
        if (!kthLargest(nums, k))
            cout << "not present" << endl;
        cout << endl;
    }
    return 0;
}