#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int,int> ladder;
    map<int,int> snake;
    for (int i=0;i<n;i++) {
        int u, v;
        cin >> u >> v;
        ladder[u] = v;
    }
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    queue<int> q;
    vector<bool> visited(101, false);
    vector<int> dist(101, 0);
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();
        for (int i=1;i<=6;i++) {
            int next = cnt + i;
            if (visited[next] || next > 100) continue;
            visited[next] = true;
            dist[next] = dist[cnt] + 1;

            if (ladder.count(next) == 1) {
                int move = ladder[next];
                visited[move]

                
            }
            q.push(next);
        }
    }

    return 0;
}