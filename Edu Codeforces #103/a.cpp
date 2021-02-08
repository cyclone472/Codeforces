#include <iostream>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (k < n) k *= ((n + k - 1) / k);
        cout << (k + n - 1) / n << '\n';
    }

    return 0;
}