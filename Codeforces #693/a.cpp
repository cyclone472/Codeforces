#include <iostream>
using namespace std;

int main (void) {
    int t;
    cin >> t;

    while (t--) {
        int w, h, n;
        cin >> w >> h >> n;

        int width = 1, height = 1;
        while (w % 2 == 0) {
            width *= 2;
            w >>= 1;
        }

        while (h % 2 == 0) {
            height *= 2;
            h >>= 1;
        }

        if (n <= width * height) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}