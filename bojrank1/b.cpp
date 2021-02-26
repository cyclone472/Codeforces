#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    int l;
    cin >> n >> l;

    ll start = -1, length = 1;
    for (int i = l; i <= 100; i++) {
        if (i*(i-1)/2 > n) break;
        // 길이 l인 연속된 수열이 존재하는지 판별
        int tmp = (i-1) * i / 2;
        if (n == tmp) {
            start = 0;
            length = i;
            break;
        }
        if ((n - tmp) % i == 0) {
            start = (n - tmp) / i;
            length = i;
            break;
        }
    }
    
    for (int i = 0; i < length; i++) {
        cout << start++ << ' ';
    }
    cout << '\n';

    return 0;
}