#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int max = n;

        vector<pii> ans;
        while(max > 2) {
            int div = 1;
            while (div * div < max) div++;

            for (int i = div + 1; i <= max; i++) {
                if (i == n) continue;
                ans.push_back(make_pair(i, n));
            }
            ans.push_back(make_pair(n, div));
            max = (max + div - 1) / div;
            if (max < div)  {
                ans.push_back(make_pair(div, n));
                ans.push_back(make_pair(div, n));
            }
        }
        ans.push_back(make_pair(n, 2));
        if (max != 2)
            ans.push_back(make_pair(n, 2));
        
        cout << ans.size() << '\n';
        for (auto& x : ans) {
            cout << x.first << ' ' << x.second << '\n';
        }
    }

    return 0;
}