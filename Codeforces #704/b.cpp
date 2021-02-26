#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<bool> exist(n+1, true);
        vector<int> ans;
        for (int& x : arr) cin >> x;

        int ptr = n; // 현재 남은 값들 중 max를 저장
        int prev = n;
        for (int i = n-1; i >= 0; i--) {
            exist[arr[i]] = false;
            if (ptr == arr[i]) {
                for (int j = i; j < prev; j++) {
                    ans.push_back(arr[j]);
                }
                prev = i;
                while (exist[ptr] == false) ptr--;
            }
        }
        for (int i = 0; i < ptr; i++) {
            ans.push_back(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}