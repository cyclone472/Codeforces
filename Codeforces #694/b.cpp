#include <iostream>
using namespace std;
#define ll long long

int dividedTimes(int n, int x) {
    int ret = 0;
    while (n % x == 0) {
        n /= x;
        ret++;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int* arr = new int[n];
        ll sum = 0;
        // Get input and find a number divided by the fewest times in x
        int minDivIdx = -1;
        int divTimes = 123456789; // Init large num
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            if (dividedTimes(arr[i], x) < divTimes) {
                divTimes = dividedTimes(arr[i], x);
                minDivIdx = i;
            }
        }

        ll ans = (divTimes + 1) * sum;
        for (int i = 0; i < minDivIdx; i++) {
            ans += arr[i];
        }
        cout << ans << '\n';
    }

    return 0;
}