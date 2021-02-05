#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mat[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                mat[i][j] = (s[j] == '0' ? 0 : 1);
            }
        }

        
    }

    return 0;
}