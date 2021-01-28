#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        multiset<int> set;
        int n; cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            int elem; cin >> elem;
            set.insert(elem);
        }
        
        vector<pair<int, int>> ans;
        multiset<int> s;
        copy(set.begin(), set.end(), s.begin());
        // 제일 큰 원소를 제외한 나머지 원소를 순회
        // 맨 처음으로 계산해야 할 원소 조사
        for (auto it = s.rbegin() + 1; it != s.rend(); it++) {
            int max = *s.rbegin();
            ans.push_back(make_pair(max, *it));
            s.erase(*it); s.erase(max);
            cout << max << '\n';

            bool ansExist = true;
            for (int i = 0; i < n; i++) {
                int tmp = *s.rbegin();
                auto nextIter = s.find(max - tmp);
                if (nextIter == s.end()) {
                    ansExist = false;
                    break;
                }
                else {
                    max = *s.rbegin();
                    ans.push_back(make_pair(max, *nextIter));
                    s.erase(max); s.erase(*nextIter);
                }
            }

            if (ansExist)
                break;
            else {
                ans.clear();
                copy(set.begin(), set.end(), s.begin());
            }
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