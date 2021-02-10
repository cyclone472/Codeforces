#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int enhance = (a + b + c) / 9;
        if ((a + b + c) % 9 != 0) cout << "NO\n";
        else if (a < enhance || b < enhance || c < enhance) cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}