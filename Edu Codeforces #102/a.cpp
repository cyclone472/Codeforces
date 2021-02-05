#include <iostream>
#include <algorithm>
using namespace std;

int a[101];

int main() {
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        bool isYes = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (d < a[i])
                isYes = false;
        }
        sort (a, a+n);

        if (isYes) cout << "YES\n";
        else       cout << (a[0] + a[1] <= d ? "YES\n" : "NO\n");
    }

    return 0;
}