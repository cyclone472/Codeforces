#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

// 현재 chain이 cycle에 참여한다면 몇 개의 vertex가 참여가능?
// guarantee a_i+1 < b_i+1.
ll addVertices (ll c, ll nexta, ll nextb) {
    if (nexta > nextb)
        return addVertices(c, nextb, nexta);
    return nexta + (c - nextb + 1);
}

ll addCycleStart (ll c, ll nexta, ll nextb) {
    if (nexta > nextb)
        return addCycleStart(c, nextb, nexta);
    return (nextb - nexta + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n), c(n);
        for (ll& x : c) cin >> x;
        for (ll& x : a) cin >> x;
        for (ll& x : b) cin >> x;

        ll cnt = addCycleStart(c[0], a[1], b[1]);
        ll ans = -1;
        bool start = false;
        for (int i = 1; i < n - 1; i++) {
            // 현재 chain에서 cycle끝내기 vs 뒤로 계속 넘기기
            ans = max(ans, cnt + c[i]);
            if (a[i+1] == b[i+1]) {
                // ai == bi면 처음부터 다시 (단절)
                // 단절점에서 시작하는 경우에 cycle에 참여 못하는 vertex가 
                // 시작점이 i인 경우 vs i+1에서 다시 시작하는 경우
                if (i == n - 2) cnt = 1, start = true;
                else {
                    cnt = max(addVertices(c[i+1], a[i+2], b[i+2]) + 1,
                            addCycleStart(c[i+1], a[i+2], b[i+2]));
                    if (addVertices(c[i+1], a[i+2], b[i+2]) > c[i+1]) {
                        ans = max(ans, c[i+1] + 1);
                        cnt = 1;
                    }
                    i++;
                }
            }
            else 
                cnt += addVertices(c[i], a[i+1], b[i+1]);
            //cout << "i : " << i << ", cnt : " << cnt << ", ans : " << ans << '\n';
        }
        cout << max(ans, cnt + c.back()) << '\n';
    }

    return 0;
}