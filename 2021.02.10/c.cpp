#include <iostream>
using namespace std;

int map[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, b;
    cin >> n >> m >> b;
    int total = b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            total += map[i][j];
        }
    }

    int height = 0;
    while (n * m * height <= total) height++;
    height--;

    int minTime = 123456789, minHeight = 123456;
    for (int i = 0; i <= height; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[j][k] < i) {
                    cnt += (i - map[j][k]);
                }
                else {
                    cnt += 2 * (map[j][k] - i);
                }
            }
        }
        
        if (cnt <= minTime) {
            minTime = cnt;
            minHeight = i;
        }
    }

    cout << minTime << ' ' << minHeight << '\n';

}