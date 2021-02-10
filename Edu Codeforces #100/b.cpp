#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 1000000000

ll f (ll x) {
    return (x < 0 ? -1 * x : x);
}

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr(n);
        for(ll& x : arr) {
            cin >> x;
            // min = (x < min ? x : min);
        }

        ll prev = arr[0];
        cout << prev << ' ';
        for (int i = 1; i < n; i++) {
            if (arr[i] > prev) {
                ll tmp1 = (arr[i] / prev) * prev;
                if (f(tmp1 - arr[i]) < f(2*tmp1 - arr[i]) || 2 * tmp1 > INF)
                    prev = tmp1;
                else prev = 2 * tmp1;
            }
            else {
                prev = gcd(arr[i], prev);
            }
            cout << prev << ' ';
        }
        cout << '\n';
    }

    return 0;
}