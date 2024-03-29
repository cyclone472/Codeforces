#include <iostream>
#include <string.h>
using namespace std;
#define ll long long

// isAns[i] = min + i�� �����������ΰ�?
bool isAns[1000001];

int main() {
    memset(isAns, 1, sizeof(isAns));
    ll min, max;
    cin >> min >> max;
    
    for (ll i = 2; i <= 1000000; i++) {
        ll squareNum = i * i;
        if (squareNum > max) break;
        // ex) min = 100, squareNum = 9, then cur = 12
        //     min = 100, squareNum = 4, then cur = 25 
        ll cur = min / squareNum;
        if (cur * squareNum < min) cur++;

        while (cur * squareNum <= max) {
            isAns[cur * squareNum - min] = false;
            cur++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= max - min; i++) {
        if (isAns[i]) ans++;
    }
    cout << ans << '\n';

    return 0;
}