#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define pli pair<long long, int>

vector<vector<pair<int,int>>> g;
int n, e;
const ll INF = 9988776655000;

// [start-end] 경로의 최단 길이
ll dijkstra(int start, int end) {
    if (start == end)
        return 0;
    //vector<bool> visited(n, false);
    vector<ll> len(n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, start});
    len[0] = 0;
    //visited[start] = true;
    while (!pq.empty()) {
        auto cnt = pq.top();
        pq.pop();
        ll w = cnt.first;
        int node = cnt.second;
        if (node == end) {
            //cout << "dijkstra " << start << " to " << end << ": " << w << '\n';
            return w;
        }
        for (auto cnt : g[node]) {
            ll weight = cnt.second;
            int next = cnt.first;
            if (w + weight < len[next]) {
                len[next] = w + weight;
                pq.push({len[next], next});
            }
        }
    }
    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> e;
    g = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());
    for (int i=0;i<e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a-1].push_back({b-1, c});
        g[b-1].push_back({a-1, c});
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;

    // 1->v1, v1->v2, v2->n, v1->n, v2->n
    // 5가지 경로를 구함
    ll path1 = dijkstra(0, v1) + dijkstra(v1, v2) + dijkstra(v2, n-1);
    ll path2 = dijkstra(0, v2) + dijkstra(v2, v1) + dijkstra(v1, n-1);
    //cout << "path1 : " << path1 << ", path2 : " << path2 << '\n';
    if (path1 >= INF && path2 >= INF)
        cout << -1 << '\n';
    else
        cout << (path1 < path2 ? path1 : path2) << '\n';
    return 0;
}