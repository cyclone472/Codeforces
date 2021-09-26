#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool board[10][10];
int n;
int dx[4] = {-1, 1, 1, -1};
int dy[4] = {-1, 1, -1, 1};

int dfs(int line, int num) {
    if (line >= 2*n-1) return 0;

    int ret = 0;
    for (int y=line;y>=0;y--) {
        int x = line - y;
        if (x >= n || y >= n || board[y][x] == false) continue;

        vector<pair<int,int>> guard;
        for (int i=0;i<4;i++) {
            int nx = x, ny = y;
            while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (board[ny][nx]) {
                    guard.push_back({ny, nx});
                    board[ny][nx] = false;
                }
                nx += dx[i];
                ny += dy[i];
            }            
        }
        ret = max(ret, dfs(line+2, num+1) + 1);

        for (auto& x : guard) {
            board[x.first][x.second] = true;
        }
    }
    ret = max(ret, dfs(line+2, num));
    return ret;
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    cout << dfs(0, 0) + dfs(1, 0) << '\n';
    return 0;
}