#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int pos = 0;

        // time 1에서 명령을 내리면 time 2부터 이동 시작
        // ex) 1 5 => (time, pos) = (2, 1), (3, 2), (4, 2)
        int t, x;
        cin >> t >> x;
        for (int i = 0; i < n; i++) {
            int nexttime, nextpos;
            cin >> t >> x;
        }
    }
    return 0;
}