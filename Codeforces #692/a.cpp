#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int parLen = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') parLen++;
            else break;
        }
        
        cout << (s.length() / 2 < parLen ? "Yes\n" : "No\n");
    }

    return 0;
}