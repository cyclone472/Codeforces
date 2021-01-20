#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n+1, vector<int>());
        vector<bool> isTeacher(n+1, false);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // BFS
        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(1);

        while(!q.empty()) {
            int cnt = q.front();
            q.pop();
            
            if (visited[cnt]) {
                continue;
            }
            visited[cnt] = true;
            
            bool adjTeacher = false;
            for(int i = 0; i < g[cnt].size(); i++) {
                int next = g[cnt][i];
                if (isTeacher[next]) {
                    adjTeacher = true;
                }
                if (!visited[next]) {
                    q.push(next);
                }
            }

            if (!adjTeacher) {
                isTeacher[cnt] = true;
            }
        }

        bool ansExist = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                ansExist = false;
                break;
            }
        }

        if (ansExist) {
            cout << "YES\n";
            int teacherNum = 0;
            for (int i = 1; i <= n; i++) {
                if (isTeacher[i])
                    teacherNum++;
            }
            cout << teacherNum << '\n';
            for (int i = 1; i <= n; i++) {
                if (isTeacher[i])
                    cout << i << ' ';
            }
            cout << '\n';
        }
        else
            cout << "NO\n";
    }

    return 0;
}