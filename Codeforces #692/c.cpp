#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        // rookRow[i] = j는 i행 j열에 룩이 있음을 의미함.
        // rookCol[j] = i는 j열에 있는 룩이 i행에 있음을 의미함.
        vector<int> rookRow(n+1, 0);
        vector<int> rookCol(n+1, 0);
        // (n,n)번째 자리가 채워졌는가?
        vector<bool> isFull(n+1, false);
        // n열로 이동할 수 있는가?
        vector<bool> canMove(n+1, true);
        int remainRook = 0; // 배치해야 할 룩의 개수
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            rookRow[x] = y;
            rookCol[y] = x;
            canMove[y] = false;
            if (x == y) isFull[x] = true;
            else remainRook++;
        }

        int deadlockNum = 0;
        for (int i = 1; i <= n; i++) {
            // 이미 제자리를 찾아갔거나 검사했으면 재검사 X
            if (isFull[i]) continue;
            // i번째 행에 룩이 있는데 (i, i)에 있는건 아니라 재배치해야 하는 경우
            if (rookRow[i] != 0 && rookRow[i] != i) {
                // (i, i)로 이동할 수 있으면 이동한다.
                if (canMove[i]) {
                    isFull[i] = true;
                    canMove[i] = false;
                    canMove[rookRow[i]] = true;
                    ans++;
                    continue;
                }
                // 이동할 수 없으면 교착 상태를 검사
                int cnt = i;
                while (!canMove[cnt]) {
                    // i열에 속한 원소는 이동 가능한지 확인
                    cnt = rookCol[cnt];
                    // 교착 상태가 완성되면 break
                    if (cnt == i) {
                        deadlockNum++;
                        break;
                    }
                }
                cnt = i;
                while (!canMove[cnt]) {
                    isFull[cnt] = true;
                    canMove[cnt] = false;
                    canMove[rookRow[i]] = true;
                    ans++;
                    cnt = rookCol[cnt];
                    if (cnt == i) break;
                }
            }
        }
        cout << ans + deadlockNum << '\n';

    }

    return 0;
}