#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> score(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n-1; i >= 0; i--) {
            score[i] = a[i];
            // if index is smaller than n, add score
            if (i + a[i] < n) {
                score[i] += score[i + a[i]];
            }
            if (ans < score[i])
                ans = score[i];
        }
        cout << ans << endl;
    }

    return 0;
}