#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        ll p; cin >> p;
        ll a[3];
        cin >> a[0] >> a[1] >> a[2];
        ll ans = max(a[0], max(a[1], a[2]));
        for (int i = 0; i < 3; i++) {
            if (p % a[i] == 0) {
                ans = 0;
                break;
            }
            ans = min(ans, a[i] - p % a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}