#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll dp[400001];
ll ans[100001];
int N, D;
const ll MIN = -(1LL<<50);

ll init(vector<int>& arr, int left, int right, int n) {
    if (left == right) {
        return dp[n] = arr[left];
    }
    int mid = (left + right) / 2;
    dp[n] = init(arr, left, mid, n*2);
    dp[n] = max(dp[n], init(arr, mid+1, right, n*2+1));
    return dp[n];
}

ll query(int left, int right, int n, int nLeft, int nRight) {
    if (nRight < left || nLeft > right) return MIN;
    if (left <= nLeft && nRight <= right) return dp[n];
    int mid = (nLeft + nRight) / 2;
    return max(query(left, right, n*2, nLeft, mid),
               query(left, right, n*2+1, mid+1, nRight));
}

ll update(ll nVal, int idx, int n, int nLeft, int nRight) {
    if (idx < nLeft || nRight < idx) { return dp[n]; }
    if (nLeft == nRight) { return dp[n] = nVal; }
    int mid = (nLeft + nRight) / 2;
    dp[n] = max(update(nVal, idx, 2*n, nLeft, mid),
                update(nVal, idx, 2*n+1, mid+1, nRight));
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> D;
    vector<int> arr(N);
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    init(arr, 0, N-1, 1);

    ll ret = ans[0] = arr[0];
    for (int i=1;i<N;i++) {
        int left = max(i-D, 0), right = i-1;
        ll prevMax = query(left, right, 1, 0, N-1);
        ans[i] = max(prevMax, 0LL) + arr[i];
        update(ans[i], i, 1, 0, N-1);
        ret = max(ret, ans[i]);
    }
    cout << ret << '\n';
    return 0;
}