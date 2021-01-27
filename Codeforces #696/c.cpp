#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int a[2001];
bool used[2001];

int main() {
    int t; cin >> t;
    while (t--) {
        memset(used, 0, sizeof(used));
        int n; cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a, a + 2*n, greater<int>());

        vector<pair<int, int>> ansOrder;
        int maxEle = a[0];
        used[0] = true;
        // n번 반복하여 모든 원소 제거
        bool ansExist = true;
        for (int i = 1; i <= n; i++) {
            for(int j = 2*n-1; j >= i+1; j--) {
                if (used[j]) continue;
                if (a[i] + a[j] > maxEle) {
                    ansExist = false;
                    break;
                }
                else if (a[i] + a[j] == maxEle) {
                    used[i] = used[j] = true;
                    ansOrder.push_back(make_pair(a[i], a[j]));
                    maxEle = a[i];
                    break;
                }
            }
            if (!ansExist) break;
        }
        
        if (ansExist) {
            cout << "YES\n";
            for (int i = 0; i < 2*n; i++) {
                if (!used[i]) {
                    cout << a[0] + a[i] << '\n';
                    cout << a[i] << ' ' << a[0] << '\n';
                    break;
                }
            }
            for (auto x : ansOrder) {
                cout << x.first << ' ' << x.second << '\n';
            }
        }
        else {
            cout << "NO\n";
            for (auto x : ansOrder) {
                cout << x.first << ' ' << x.second << '\n';
            }
        }
    }
    return 0;
}