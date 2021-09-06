#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] < a[i + 1]) {
				while (2 * a[i] < a[i + 1]) {
					ans++;
					a[i] *= 2;
				}
			}
			else if (a[i] > a[i + 1]) {
				while (a[i] > 2 * a[i + 1]) {
					ans++;
					a[i] = (a[i] + 1) / 2;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}