#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> occur[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ss, ts; // ssize, tsize
    cin >> ss >> ts;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < ss; i++) {
        occur[s[i] - 'a'].push_back(i);
    }

    vector<int> left(ts), right(ts);
    int ptr = 0;
    for (int i = 0; i < ss; i++) {
        while (t[ptr] != s[i]) i++;
        left[ptr] = i;
        ptr++;
        if (ptr == ts) break;
    }
    ptr--;
    for (int i = ss-1; i >= 0; i--) {
        while (t[ptr] != s[i]) i--;
        right[ptr] = i;
        ptr--;
        if (ptr == -1) break;
    }
    /*
    cout << "left : ";
    for (int& x : left) cout << x << ' ';
    cout << '\n';
    cout << "right : ";
    for (int& x : right) cout << x << ' ';
    cout << '\n';   
    */
    int ans = -1;
    for (int i = 0; i < ts - 1; i++) {
        int width = right[i+1] - left[i];
        ans = (ans < width ? width : ans);
    }
    cout << ans << '\n';
    return 0;
}