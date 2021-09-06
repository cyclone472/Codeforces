#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int INF = (1 << 27);
set<pair<int, int>> ans;

void restore_path(vector<vector<int>>& path, int u, int v) {
	if (path[u][v] == -1) {
		ans.insert({ u, v });
		return;
	}
	int w = path[u][v];
	restore_path(path, u, w);
	restore_path(path, w, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, INF));
	vector<vector<int>> path(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		g[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a - 1][b - 1] = c;
		g[b - 1][a - 1] = c;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					path[i][j] = k;
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}

	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	p1--; p2--; p3--;

	int mincost = INF, idx = -1;
	for (int i = 0; i < n; i++) {
		if (mincost > g[i][p1] + g[i][p2] + g[i][p3]) {
			mincost = g[i][p1] + g[i][p2] + g[i][p3];
			idx = i;
		}
	}

	restore_path(path, p1, idx);
	restore_path(path, p2, idx);
	restore_path(path, p3, idx);
	cout << mincost << ' ' << ans.size() << '\n';
	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << (iter->first) + 1 << ' ' << (iter->second) + 1 << '\n';
	}

	return 0;
}