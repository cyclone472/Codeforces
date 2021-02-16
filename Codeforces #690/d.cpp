#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int arr[3001];

vector<ll> factorization(ll num) {
    vector<ll> ret(1, 1);
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            ret.push_back(i);
            ret.push_back(num/i);
        }
    }
    ret.push_back(num);
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        ll sum = 0, maxElem = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            maxElem = (maxElem < arr[i] ? arr[i] : maxElem);
        }

        vector<ll> factor = factorization(sum);
        ll ans = 123456789;
        // 각 원소를 sum / x로 맞출 수 있는가?
        for (ll& x : factor) {
            //cout << "x : " << x << '\n';
            if ((sum / x) < maxElem) continue;
            else if (x > n) break;

            int elem = 0;
            ll cntAns = -1;
            bool canAns = true;
            for (int i = 0; i < n; i++) {
                if (elem == sum/x) elem = arr[i];
                else if (elem > sum/x) {
                    canAns = false;
                    break;
                }
                else {
                    cntAns++;
                    elem += arr[i];
                }
            }
            if (canAns && elem == sum / x) {
                //cout << "sum / x : " << sum/x << '\n';
                ans = (cntAns < ans ? cntAns : ans);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}