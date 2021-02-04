#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s = "989";

        if (n <= 3) cout << s.substr(0, n) << '\n';
        else {
            cout << s;
            for (int i = 0; i < n - 3; i++) {
                cout << i % 10;
            }
            cout << '\n';
        }
    }

    return 0;
}