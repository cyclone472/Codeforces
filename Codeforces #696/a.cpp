#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int prev = -100;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            int add;
            if (s[i] == '0') {
                add = (prev == 1 ? 0 : 1);
            }
            else {
                add = (prev == 2 ? 0 : 1);
            }
            prev = add + (int)(s[i] - '0');
            //cout << "Prev : " << prev << '\n';
            ans += to_string(add);
        }
        cout << ans << '\n';
    }

    return 0;
}