#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[50001];
vector<int> squ;

int solve (int x) {
    if (dp[x] != 0) return dp[x];

    int ret = 12345;
    for (int i = 0; i < squ.size() && squ[i] < x; i++) {
        ret = min(ret, solve(x-squ[i]) + 1);
    }
    return dp[x] = ret;
}

int main() {
    for (int i = 1; i * i <= 50000; i++) {
        squ.push_back(i*i);
        dp[i*i] = 1;
    }

    int n;
    cin >> n;
    cout << solve(n) << '\n';
    return 0;
}