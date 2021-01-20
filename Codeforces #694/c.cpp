#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int* k = new int[n];
        int* cost = new int[m];
        for (int i = 0; i < n; i++) {
            cin >> k[i];
            k[i]--;
        }
        for (int i = 0; i < m; i++) {
            cin >> cost[i];
        }
        sort(k, k + n, greater<int>());
        
        ll ans = 0;
        int cheapest = 0; // Index of remain cheapest present
        for (int i = 0; i < n; i++) {
            if (cheapest < k[i]) {
                // Give a cheapest present to a friend
                ans += cost[cheapest++];
            }
            else {
                ans += cost[k[i]];
            }
            //cout << "cheapest : " << cheapest << ", k[i] : " << k[i] << '\n';
        }
        cout << ans << '\n';
    }

    return 0;
}