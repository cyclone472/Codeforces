#include <iostream>
using namespace std;

int r[101], b[101];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (r[i] >= 0) {
                ans += r[i];
            }
            else {
                //cout << "i : " << i << '\n';
                int partialSum = 0;
                while(partialSum <= 0 && i < n) {
                    partialSum += r[i];
                    if (partialSum > 0) {
                        ans += partialSum;
                        break;
                    }
                    else
                        i++;
                }
                
                //cout << "R partial Sum : " << partialSum << '\n';
            }
        }
        for (int i = 0; i < m; i++) {
            if (b[i] >= 0) {
                ans += b[i];
            }
            else {
                //cout << "i : " << i << '\n';
                int partialSum = 0;
                while(partialSum <= 0 && i < m) {
                    partialSum += b[i];
                    if (partialSum > 0) {
                        ans += partialSum;
                        break;
                    }
                    else
                        i++;
                }

                //cout << "B partial Sum : " << partialSum << '\n';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}