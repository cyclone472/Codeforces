#include <iostream>
#include <algorithm>
using namespace std;

int h[200001];
int fMax[200001], fMin[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int k; cin >> k;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        fMin[0] = fMax[0] = h[0];
        bool canBuild = true;
        for (int i = 1; i < n; i++) {
            fMin[i] = max(h[i], fMin[i-1] - k + 1);
            fMax[i] = min(fMax[i-1] + k - 1, h[i] + k - 1);
            if (fMin[i] > fMax[i]) {
                canBuild = false;
                break;
            }
        }
        if (fMin[n-1] > h[n-1] || h[n-1] > fMax[n-1]) {
            canBuild = false;
        }
        
        cout << (canBuild ? "YES\n" : "NO\n");
    }

    return 0;
}