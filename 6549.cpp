#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
#define ll long long

ll cal(vector<ll>& arr, int s, int e) {
    if (s > e) { return 0; }
    else if (s == e) { return arr[s]; }

    ll x = (s + e) / 2;
    ll ret = max(cal(arr, s, x), cal(arr, x+1, e));
    ll p1 = x, p2 = x+1, h = min(arr[x], arr[x+1]);
    ll cmax = h * 2;
    while (s < p1 || p2 < e) {
        if (p2 < e && (p1 == s || arr[p1-1] < arr[p2+1])) {
            h = min(h, arr[++p2]);
            cmax = max(cmax, h * (p2 - p1 + 1));
        }
        else {
            h = min(h, arr[--p1]);
            cmax = max(cmax, h * (p2 - p1 + 1));
        }
        //cout << cmax << ' ' << h << ' ' << p1 << ' ' << p2 << ' ' << s << ' ' << e << ' ' << x << '\n';
    }
    return max(ret, cmax);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n; cin >> n;
        if (n == 0) { break; }
        vector<ll> arr(n);
        for (int i=0;i<n;i++) cin >> arr[i];
        cout << cal(arr, 0, n-1) << '\n';
    }

    return 0;
}