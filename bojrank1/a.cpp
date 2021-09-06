#include <iostream>
#include <algorithm>
using namespace std;

char map[51][51];

int check (int x, int y) {
    int ret1 = 0, ret2 = 0;
    bool mustW = true;
    for (int i = x; i < x+8; i++) {
        for (int j = y; j < y+8; j++) {
            if ((map[i][j] == 'W' && !mustW) || 
                (map[i][j] == 'B' && mustW)) {
                ret1++;
            }
            mustW = !mustW;
        }
        mustW = !mustW;
    }

    mustW = false;
    for (int i = x; i < x+8; i++) {
        for (int j = y; j < y+8; j++) {
            if ((map[i][j] == 'W' && !mustW) || 
                (map[i][j] == 'B' && mustW)) {
                ret2++;
            }
            mustW = !mustW;
        }
        mustW = !mustW;
    }
    return min(ret1, ret2);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 123456789;
    for (int i = 0; i <= n-8; i++) {
        for (int j = 0; j <= m-8; j++) {
            ans = min(ans, check(i, j));
        }
    }
    cout << ans << '\n';

    return 0;
}