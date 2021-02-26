#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> x(a+b), y(a+b);
    for (int i = 0; i < b; i++) {
        x[i] = y[i] = 1;
    }
    for (int i = b; i < a+b; i++) {
        x[i] = y[i] = 0;
    }

    if (a == 0 || b == 1) {
        if (k != 0) {
            cout << "NO\n";
        }
        else {
            cout << "Yes\n";
            for (int& t : x) cout << t;
            cout << '\n';
            for (int& t : y) cout << t;
            cout << '\n';
        }
        return 0;
    }    
    else if (k > a + b - 2) {
        cout << "No\n";
        return 0;
    }

    if (a >= k) {
        y[b-1] = 0;
        y[b+k-1] = 1;
    }
    else {
        y[b-1] = 0;
        y[y.size()-1] = 1;
        k -= a;

        for (int i = 0; i < k; i++) {
            y[b-2-i] = 0;
            y[b-1-i] = 1;
        }    
    }
    cout << "Yes\n";
    for (int& t : x) cout << t;
    cout << '\n';
    for (int& t : y) cout << t;
    cout << '\n';

    return 0;
}