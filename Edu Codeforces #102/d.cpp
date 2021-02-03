#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s; cin >> s;
        
        // prefix.first = minimum, prefix.second = maximum
        vector<pii> prefix (n + 1);
        vector<pii> suffix (n + 2);
        vector<int> val(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int nextMin = prefix[i-1].first;
            int nextMax = prefix[i-1].second;
            if (s[i-1] == '+') {
                if (val[i-1] == prefix[i-1].second)
                    nextMax++;
                val[i] = val[i-1] + 1;
            }
            else {
                if (val[i-1] == prefix[i-1].first)
                    nextMin--;
                val[i] = val[i-1] - 1;
            }
            prefix[i] = make_pair(nextMin, nextMax);
        }

        int cur = val[n];
        suffix[n] = make_pair(val[n], val[n]);
        for (int i = n - 1; i >= 0; i--) {
            int nextMin = suffix[i+1].first;
            int nextMax = suffix[i+1].second;

            // Calculate inversely to restore the original in/decrease
            if (s[i] == '+') {
                if (cur == suffix[i+1].first)
                    nextMin--;
                cur--;
            }
            else {
                if (cur == suffix[i+1].second)
                    nextMax++;
                cur++;
            }
            suffix[i] = make_pair(nextMin, nextMax);
        }
        
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            
            int preMin = prefix[l-1].first, preMax = prefix[l-1].second;
            int sufMin = (val[l-1] - val[r]) + suffix[r].first;
            int sufMax = (val[l-1] - val[r]) + suffix[r].second;
            cout << max(preMax, sufMax) - min(preMin, sufMin) + 1 << '\n';
        }
    }


    return 0;
}