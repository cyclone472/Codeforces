#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string mult(string s, int n) {
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret += s;
    }
    return ret;
}

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    return (b == 0 ? a : gcd (b, a % b));
}


int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--) {
        string s, t; cin >> s >> t;

        int l1 = s.size(), l2 = t.size();
        int lcmNum = lcm(l1, l2);

        if (mult(s, lcmNum/l1) == mult(t, lcmNum/l2))
            cout << mult(s, lcmNum/l1) << "\n";
        else
            cout << -1 << '\n';
        
    }

    return 0;
}