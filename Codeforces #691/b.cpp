#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    
    if (n % 2 == 0) cout << (n / 2 + 1) * (n / 2 + 1) << '\n';
    else cout << ((n + 2) * (n + 2)) / 2 << '\n';
    return 0;
}