#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x > 45) {
            cout << "-1\n";
            continue;
        }

        int ans = 0;
        for (int i = 1, num = 9; x > 0; i *= 10, num--) {
            if (x > num) {
                ans += (i * num);
                x -= num;
            }
            else {
                ans += (i * x);
                x -= x;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}