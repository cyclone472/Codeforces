#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define pi pair<int, pair<int, int>>

int map[101][101];
int dp[101][101];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void input() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = 987654321;
        }
    }

    vector<string> mm(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> mm[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[i][j] = (mm[i][j-1] - '0');
        }
    }
}

int main() {
    cin >> m >> n;
    input();

    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push(make_pair(0, make_pair(1, 1)));
    dp[1][1] = 0;
    //visited[1][1] = true;
    int minnum = 0;
    while (!q.empty()) {
        auto cnt = q.top().second;
        int x = cnt.first, y = cnt.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (dp[nx][ny] > dp[x][y]) {
                dp[nx][ny] = dp[x][y] + map[nx][ny];
            }
            dp[nx][ny] = min(dp[nx][ny], dp[x][y] + map[nx][ny]);
            q.push(make_pair(dp[nx][ny], make_pair(nx, ny)));
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << dp[n][m] << '\n';

    return 0;
}