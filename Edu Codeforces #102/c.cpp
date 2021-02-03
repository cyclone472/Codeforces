#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        for (int i = 0; i < (k - 1) - (n - k); i++) {
            cout << (i + 1) << ' ';
        }
        for (int i = 0; i <= n - k; i++) {
            cout << (k - i) << ' ';
        }
        cout << '\n';
        // 1 2 3 4 3 2 1, d = 1 -> [4]
        // 1 2 3 4 => p = [1,2,3,4]
    }

    return 0;
}