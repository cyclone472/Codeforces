#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int can1 = 0, can2 = 0;
        while (n--) {
            int cnt;
            cin >> cnt;

            if (cnt == 1) can1++;
            else          can2++;
        }

        // 4 Cases : (weight1 candy, weight2 candy) is
        // (odd, odd), (odd, even), (even, odd), (even, even)
        if ((can1 % 2 == 1) && (can2 % 2 == 1))
            cout << "NO\n";
        else if ((can1 % 2 == 1) && (can2 % 2 == 0))
            cout << "NO\n";
        else if ((can1 % 2 == 0) && (can2 % 2 == 1)) {
            if (can1 == 0)  cout << "NO\n";
            else            cout << "YES\n";
        }
        else
            cout << "YES\n"; 
    }

    return 0;
}