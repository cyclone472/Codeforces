#include <iostream>
using namespace std;

int main() {
    int c, r, k;
    cin >> c >> r >> k;
    
    if (k > c * r) {
        cout << 0 << '\n';
        return 0;
    }

    bool rIsAdd = true, cIsAdd = true;
    int sum = 0;
    int x = 1, y = 0;
    for (int i = 0;; i++) {
        if (k < sum)
            break;
        // 세로로 더함
        if (i % 2 == 0) {
            y += (rIsAdd ? r - i/2 : i/2 - r);
            rIsAdd = !rIsAdd;
            sum += (r - i/2);
            if (k <= sum) {
                y -= (i % 4 == 0 ? sum - k : k - sum);
                break;
            }
        }
        else {
            x += (cIsAdd ? c - (i+1)/2 : (i+1)/2 - c);
            cIsAdd = !cIsAdd;
            sum += (c - (i+1)/2);
            if (k <= sum) {
                x -= (i % 4 == 1 ? sum - k : k - sum);
                break;
            }
        }
    }
    cout << x << ' ' << y << '\n';

    return 0;
}