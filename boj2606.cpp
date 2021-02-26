#include <iostream>
#include <vector>
using namespace std;

bool infested[101];

int main () {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < k; i++) {
        int a, b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (infested[i]) ans++;
    }
    cout << ans << '\n';

    return 0;
}