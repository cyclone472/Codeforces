#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(2*n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());

        vector<pair<int, int>> ans;
        // 제일 큰 원소를 제외한 나머지 원소를 순회하며
        // 맨 처음으로 계산해야 할 원소 조사
        for (int i = 1; i < 2*n; i++) {
            multiset<int> s;
            for (auto& x : a) { s.insert(x); }

            ans.push_back(make_pair(a[0], a[i]));
            s.erase(s.find(a[0])); s.erase(s.find(a[i]));
            int x = a[0];
            bool ansExist = true;
            while (!s.empty()) {
                /*cout << "s : ";
                for(auto it = s.begin(); it != s.end(); it++) {
                    cout << *it << ' ';
                }
                cout << '\n';*/
                int ans1 = *s.rbegin();
                s.erase(s.find(ans1));
                int ans2 = x - ans1;
                // if s doesn't have ans2
                if (s.find(ans2) == s.end()) {
                    ansExist = false;
                    break;
                }
                else {
                    ans.push_back(make_pair(ans1, ans2));
                    s.erase(s.find(ans2));
                    x = ans1;
                }
            }

            if (ansExist) break;
            else ans.clear();
        }
        
        if (ans.size() == n) {
            cout << "YES\n" << ans[0].first + ans[0].second << '\n';
            for (auto x : ans) {
                cout << x.first << ' ' << x.second << '\n';
            }
        }
        else
            cout << "NO\n";
    }
    return 0;
}