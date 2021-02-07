#include <iostream>
using namespace std;
#define ll long long

bool isFair(ll num) {
    bool isInclude[10];
    for (bool& x : isInclude) x = false;
    ll n = num;
    while (n != 0) {
        isInclude[n % 10] = true;
        n /= 10;
    }

    for (int i = 1; i < 10; i++) {
        if (isInclude[i] && num % i != 0) 
            return false;
    }
    return true;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        while(!isFair(n)) n++;
        cout << n << '\n';
    }

    return 0;
}