#include <iostream>
#include <string.h>
using namespace std;
#define ll long long

bool isPrime[1000001];

void eratos() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 1000001; i++) {
        if(isPrime[i]) {
            for (int j = 2 * i; j < 1000001; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    eratos();
    int t; cin >> t;
    while(t--) {
        int d; cin >> d;
        ll ans = 1;
        ll prev = d + 1;
        for (int i = 0; i < 2; i++) {
            while(!isPrime[prev]) {
                prev++;
            }
            ans *= prev;
            prev += d;
        }

        cout << ans << '\n';
    }

    return 0;
}