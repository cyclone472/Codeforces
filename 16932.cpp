#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int,int> parent[1001][1001];
vector<vector<bool>> visited;
map<pair<int,int>, int> mass;
vector<vector<int>> arr;

pair<int,int> find(int y, int x) {
    if (parent[y][x] != make_pair(y, x)) {
        parent[y][x] = find(parent[y][x].first, parent[y][x].second);
    }
    return parent[y][x];
}

void merge(pair<int,int> u, pair<int,int> v) {
    auto pu = find(u.first, u.second);
    auto pv = find(v.first, v.second);
    if (pu != pv) {
        if (pu < pv) parent[pv.first][pv.second] = {pu.first, pu.second};
        else         parent[pu.first][pu.second] = {pv.first, pv.second};
    }
}

void getMass() {
    vector<pair<int,int>> v;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            // bfs로 덩어리의 크기를 알아내서 map에 기록
            if (!visited[i][j] && arr[i][j] == 1) {
                int massSize = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while (!q.empty()) {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    for (int i=0;i<4;i++) {
                        int ny = cy + dy[i], nx = cx + dx[i];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                            visited[ny][nx] || arr[ny][nx] == 0)
                            continue;
                        massSize++;
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
                mass[parent[i][j]] = massSize;
            }
        }
    }
}

int main() {
    for (int i=0;i<1001;i++) {
        for (int j=0;j<1001;j++) {
            parent[i][j] = {i,j};
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++)
            cin >> arr[i][j];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j] == 1) {
                if (i+1 < n && arr[i+1][j] == 1) merge({i,j}, {i+1,j});
                if (j+1 < m && arr[i][j+1] == 1) merge({i,j}, {i,j+1});
            }
        }
    }
    /*
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            printf("(%d,%d) ", parent[i][j].first, parent[i][j].second);
        }
        printf("\n");
    }*/
    getMass();

    int ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j] == 0) {
                int mas = 1;
                set<pair<int,int>> s;
                for (int k=0;k<4;k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (y < 0 || y >= n || x < 0 || x >= m) continue;
                    if (arr[y][x] == 1 && s.find(parent[y][x])==s.end()) {
                        mas += mass[parent[y][x]]; 
                        s.insert(parent[y][x]);
                        //printf("(%d, %d) : %d\n", y, x,mas);
                    }
                }
                ans = max(ans, mas);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}