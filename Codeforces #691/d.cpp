#include <iostream>
using namespace std;
#define ll long long

ll x[100][100];

ll c(int n, int r) {
    if (n == r || r == 0) return 1;
    if (x[n][r] != 0) return x[n][r];
    return x[n][r] = c(n-1, r) + c(n-1, r-1);
}

int main() {
    cout << c(100, 50) << '\n';

    return 0;
}