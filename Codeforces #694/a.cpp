#include <iostream>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        
        ll* arr = new ll[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Minimal possible beauty : Add all element
        // Maximal possible beauty : Round up all element
        ll min = 0, max = 0;
        for (int i = 0; i < n; i++) {
            min += arr[i];
            max += ((arr[i] + x - 1) / x); // Round up
        }
        cout << (min + x - 1) / x << ' ' << max << '\n';
    }

}