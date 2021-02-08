#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

// ���� chain�� cycle�� �����Ѵٸ� �� ���� vertex�� ��������?
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
            // ���� chain���� cycle������ vs �ڷ� ��� �ѱ��
            ans = max(ans, cnt + c[i]);
            if (a[i+1] == b[i+1]) {
                // ai == bi�� ó������ �ٽ� (����)
                // ���������� �����ϴ� ��쿡 cycle�� ���� ���ϴ� vertex�� 
                // �������� i�� ��� vs i+1���� �ٽ� �����ϴ� ���
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