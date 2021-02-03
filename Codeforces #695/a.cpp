#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string ans = "";
        string s = "987654321";

        if (n == 1) cout << "9\n";
        else if (n == 2) cout << "98\n";
        else if (n == 3) cout << "989\n";
        else {
            string ans = "989";
            n -= 3;
            int add = 0;
            for (int i = 0; i < n/2; i++) {
                ans += to_string(add++);
                if (add == 10) add = 0;
            }
            string add2 = "";
            add = 0;
            for (int i = 0; i < n/2 + n%2; i++) {
                add2 = to_string(add++) + add2;
                if (add == 10) add = 0;
            }
            ans += add2;
            cout << ans << '\n';
        }
    }

    return 0;
}