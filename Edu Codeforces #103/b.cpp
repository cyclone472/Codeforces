#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> p(n);
        for(ll& x : p) {
            cin >> x;
        }

        ll ans = 0;
        ll sum = p[0];
        for (int i = 1; i < n; i++) {
            if (sum < (p[i] * 100 + k - 1) / k) {
                ans = max(ans, ((p[i] * 100 + k - 1) / k) - sum);
            }
            sum += p[i];
        }
        cout << ans << '\n';

    }

    return 0;
}