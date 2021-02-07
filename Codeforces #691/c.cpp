#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;
    sort(a.begin(), a.end());

    vector<ll> diff;
    for (int i = 1; i < n; i++) {
        diff.push_back(a[i] - a[i-1]);
    }
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            cout << a[0] + b[i] << ' ';
        }
        return 0;
    }

    sort(diff.begin(), diff.end());

    ll diffGCD = diff[0];
    for (ll& x : diff) {
        diffGCD = gcd(x, diffGCD);
    }

    for (int i = 0; i < m; i++) {
        cout << gcd(a[0] + b[i], diffGCD) << ' ';
    }

    return 0;
}