#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define MOD 1000000007

int a[1001];
ll comb[1001][1001];

ll C(int n, int r) {
    if (comb[n][r] != 0) return comb[n][r];

    if (n == r || r == 0) return 1;
    return comb[n][r] = (C(n-1, r) + C(n-1, r-1)) % MOD;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int,int> m; 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        sort (a, a+n, greater<int>());

        ll ans = 0;
        int ptr = 0;
        while(k - m[a[ptr]] > 0) {
            k -= m[a[ptr]];
            ptr += m[a[ptr]];
        }

        cout << C(m[a[ptr]], k) << '\n';

    }

    return 0;
}