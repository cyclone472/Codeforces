#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        // rookRow[i] = j�� i�� j���� ���� ������ �ǹ���.
        // rookCol[j] = i�� j���� �ִ� ���� i�࿡ ������ �ǹ���.
        vector<int> rookRow(n+1, 0);
        vector<int> rookCol(n+1, 0);
        // (n,n)��° �ڸ��� ä�����°�?
        vector<bool> isFull(n+1, false);
        // n���� �̵��� �� �ִ°�?
        vector<bool> canMove(n+1, true);
        int remainRook = 0; // ��ġ�ؾ� �� ���� ����
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
            // �̹� ���ڸ��� ã�ư��ų� �˻������� ��˻� X
            if (isFull[i]) continue;
            // i��° �࿡ ���� �ִµ� (i, i)�� �ִ°� �ƴ϶� ���ġ�ؾ� �ϴ� ���
            if (rookRow[i] != 0 && rookRow[i] != i) {
                // (i, i)�� �̵��� �� ������ �̵��Ѵ�.
                if (canMove[i]) {
                    isFull[i] = true;
                    canMove[i] = false;
                    canMove[rookRow[i]] = true;
                    ans++;
                    continue;
                }
                // �̵��� �� ������ ���� ���¸� �˻�
                int cnt = i;
                while (!canMove[cnt]) {
                    // i���� ���� ���Ҵ� �̵� �������� Ȯ��
                    cnt = rookCol[cnt];
                    // ���� ���°� �ϼ��Ǹ� break
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