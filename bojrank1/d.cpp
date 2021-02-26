#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[101][101];
int dp[101][101];
bool visited[101][101];
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
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }*/

    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    dp[1][1] = 0;
    visited[1][1] = true;
    
    while (!q.empty()) {
        vector<pair<int, int>> wall;
        int val;
        while (!q.empty()) {
            auto cnt = q.front();
            int x = cnt.first, y = cnt.second;
            q.pop();
            val = dp[x][y];
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }
                if (visited[nx][ny]) continue;

                if (map[nx][ny] == 1) wall.push_back(make_pair(nx, ny));
                else {
                    dp[nx][ny] = dp[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
        }
        for (auto& x : wall) {
            if (!visited[x.first][x.second]) {
                dp[x.first][x.second] = val + 1;
                visited[x.first][x.second] = true;
                q.push(make_pair(x.first, x.second));
            }
        }
    }
    // 0인거 다 색칠하고
    // 1을 만나면 vector에다가 기록
    // vector에 저장된 모든 원소들에 대해 cnt + 1 후 queue에다 push

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