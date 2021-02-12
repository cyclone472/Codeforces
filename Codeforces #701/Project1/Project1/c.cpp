#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;

		ll ans = 0;
		for (int i = 2; (i - 1) * (i + 1) <= x && i <= y; i++) {
			ll cnt = min(x / (i - 1), (y + 1)) - i;
			ans += cnt;
		}
		cout << ans << '\n';
	}

	return 0;
}