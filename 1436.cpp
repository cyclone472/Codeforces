#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0, num = 666;
    while (i < n) {
        int cnt = num;
        bool find = false;
        while(cnt != 0) {
            if (cnt % 1000 != 666) cnt /= 10;
            else {
                find = true;
                break;
            }
        }
        if (find) {
            i++;
        }
        num++;
    }
    cout << num << '\n';

    return 0;
}