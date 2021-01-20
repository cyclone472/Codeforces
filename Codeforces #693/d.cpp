#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        vector<ll> even;
        vector<ll> odd;
        
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        //for (int i = 0; i < even.size(); i++) {
        //    cout << even[i] << "    asdf\n";
        //}

        ll alice = 0, bob = 0;
        while(!(even.empty() && odd.empty())) {
            // Alice moves first.
            // if even number is gone or odd number is larger than even,
            // then pick odd number.
            //cout << even.size() << "   " << odd.size() << '\n';
            if (odd.empty()) {
                alice += even.back();
                even.pop_back();
            }
            else if (even.empty() || (even.back() < odd.back()))
                odd.pop_back();
            else {
                alice += even.back();
                even.pop_back();
            }
                
            // Bob moves next.
            // if all number is picked then break
            if (even.empty() && odd.empty()) {
                break;
            }

            if (even.empty()) {
                bob += odd.back();
                odd.pop_back();
            }
            else if (odd.empty() || (odd.back() < even.back()))
                even.pop_back();
            else {
                bob += odd.back();
                odd.pop_back();
            }
        }

        if (alice < bob)
            cout << "Bob\n";
        else if (alice > bob)
            cout << "Alice\n";
        else
            cout << "Tie\n";
    }

    return 0;
}