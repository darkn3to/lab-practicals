#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    int x, key, t, comp=0, f=0;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-->0) {
        cout << "Enter the elements of the array: ";
        cin >> x;
        while (x!=-1) {
            v.push_back(x);
            cin >> x;
        }
        cout << "Enter the key: ";
        cin >> key;
        for (auto it:v) {
            if (it==key) {
                f=1;
                break;
            }
            ++comp;
        }
        if (f==1) cout << "Present " << comp << endl;
        else cout << "Not Present " << endl;
    }
}