#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll c[200001][4];

int main() {
    c[1][1] = c[2][2] = c[3][3] = 1;
    c[2][1] = 2, c[3][1] = 3, c[3][2] = 3;
    for (int n = 4; n < 200001; n++) {
        c[n][1] = n;
        c[n][2] = c[n-1][1] + c[n-1][2];
        c[n][3] = c[n-1][2] + c[n-1][3];
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int& x : arr) cin >> x;
        sort(arr.begin(), arr.end());
        arr.push_back(123456789);

        ll ans = 0;
        int lo = 0, hi = 0;
        while (arr[hi] != arr.back()) {
            while (arr[lo] + 2 >= arr[hi]) hi++;
            ans += c[hi-lo][3];
            //cout << "lo : " << lo << ", hi : " << hi << ", c[hi-lo][3] : " << c[hi-lo][3] << ", prevHi : " << prevHi << '\n';
            while (arr[lo] + 2 < arr[hi]) lo++;
            if (hi - lo >= 3) {
                ans -= c[hi-lo][3];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}