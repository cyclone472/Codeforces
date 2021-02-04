#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a1(n1), a2(n2), a3(n3);
    int min1 = 1234567890, min2 = 1234567890;
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    for (int& x : a1) {
        cin >> x;
        sum1 += x;
        if (x < min1) {
            if (x < min2) {
                min1 = min2;
                min2 = x;
            }
            else min1 = x;
        }
    }
    for (int& x : a2) {
        cin >> x;
        sum2 += x;
        if (x < min1) {
            if (x < min2) {
                min1 = min2;
                min2 = x;
            }
            else min1 = x;
        }
    }
    for (int& x : a3) {
        cin >> x;
        sum3 += x;
        if (x < min1) {
            if (x < min2) {
                min1 = min2;
                min2 = x;
            }
            else min1 = x;
        }
    }

    int minSum = min(sum1, min(sum2, sum3));
    int totSum = sum1 + sum2 + sum3;
    cout << min(totSum - 2 * (min1 + min2), totSum - minSum) << '\n';

    return 0;
}