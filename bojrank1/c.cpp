#include <iostream>
#include <map>
using namespace std;
#define ll long long

map<ll, ll> m;
ll n, p, q;

ll solve (ll x) {
    if (x == 0) return 1;
    else if (m.count(x) == 1) return m[x];
    m[x] = solve(x/p) + solve(x/q);
    return m[x];
}

int main() {
    cin >> n >> p >> q;
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }

    cout << solve(n) << '\n';

    return 0;
}