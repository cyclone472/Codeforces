#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

const ll MOD = 1000000007;
ll c[200001][101];

int main() {
    for (int n = 1; n < 200001; n++) {
        c[n][1] = n;
    }
    for (int n = 2; n < 200001; n++) {
        for (int r = 2; r <= min(n, 100); r++) {
            c[n][r] = (c[n-1][r-1] + c[n-1][r]) % MOD;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        for(int& x : arr) cin >> x;
        sort(arr.begin(), arr.end());
        arr.push_back(123456789);

        ll ans = 0;
        int lo = 0, hi = 0;
        while (arr[hi] != arr.back()) {
            while (arr[lo] + k >= arr[hi]) hi++;
            ans = (ans + c[hi-lo][m]) % MOD;
            while (arr[lo] + k < arr[hi]) lo++;
            if (hi - lo >= m) {
                ans = (ans - c[hi-lo][m] + MOD) % MOD;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}