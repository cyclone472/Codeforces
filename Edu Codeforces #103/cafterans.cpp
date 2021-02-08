#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n), c(n);
        for(ll& x : c) cin >> x;
        for(ll& x : a) cin >> x;
        for(ll& x : b) cin >> x;

        ll* dp = new ll[n];
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            ll diff = (a[i] > b[i] ? a[i] - b[i] : b[i] - a[i]);
            if (diff == 0)
                dp[i] = c[i] + 1;
            else
                dp[i] = max(dp[i-1] + c[i] + 1 - diff, c[i] + diff + 1);
        }

        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}