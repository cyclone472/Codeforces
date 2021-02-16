#include <iostream>
using namespace std;

int arr[301];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int p1 = 0, p2 = n-1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) cout << arr[p1++] << ' ';
            else            cout << arr[p2--] << ' ';
        }
        cout << '\n';
    }

    return 0;
}