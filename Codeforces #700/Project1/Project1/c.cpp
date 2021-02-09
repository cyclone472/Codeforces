#include <iostream>
using namespace std;

int arr[100002];

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "! 1" << '\n';
        return 0;
    }
    arr[0] = 123456789, arr[n+1] = 123456789;

    int lo = 1, hi = n;
    int ans = -1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << mid << '\n';
        cout.flush();
        int ret;
        cin >> ret;

        cout << "? " << mid + 1 << '\n';
        cout.flush();
        int ret2;
        cin >> ret2;

        if (ret < ret2)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << "! " << (lo + hi) / 2 << '\n';

    return 0;
}