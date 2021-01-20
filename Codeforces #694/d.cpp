#include <iostream>
#include <map>
using namespace std;
#define ll long long

int arr[300001];

int preprocess(int num) {
    //factorization and remove exponent is even
    int ret = 1;
    int n = num;
    for (int i = 2; i * i <= n; i++) {
        int exponent = 0;
        while (num % i == 0) {
            num /= i;
            exponent++;
        }
        if (exponent % 2 == 1) {
            ret *= i;
        } 
    }

    if (num > 1)
        ret *= num;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        map<int, int> m1, m2;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] = preprocess(arr[i]);
            m1[arr[i]]++;
        }
        m2[1] = 0;

        int zeroAns = 0;
        for (auto it = m1.begin(); it != m1.end(); it++) {
            if (it->second % 2 == 0) {
                m2[1] += it->second;
            }
            else {
                m2[it->first] = it->second;
            }

            if (zeroAns < it->second)
                zeroAns = it->second; 
        }

        int otherAns = 0;
        for (auto it = m2.begin(); it != m2.end(); it++) {
            if (otherAns < it->second)
                otherAns = it->second;
        }
        
        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            ll w;
            cin >> w;

            if (w == 0) cout << zeroAns << '\n';
            else cout << otherAns << '\n';
        }
        /*
        cout << "HI : ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        */
    }

    return 0;
}