#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        // 2020XXX ...
        // XXX...2020
        // 2XXXXX020, 20XXXX20, 202XXXXX0
        if (s.substr(0, 4) == "2020" || s.substr(n-4, 4) == "2020") {
            cout << "YES\n";
        }
        else if(s[0] == '2' && s[n-1] == '0') {
            if(s.substr(n-3, 2) == "02" || (s[1] == '0' && s[n-2] == '2') ||
                (s[1] == '0' && s[2] == '2')) {
                    cout << "YES\n";
                }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}