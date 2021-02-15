#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAX = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<ll> arr;
	for (ll a = 3; a * a <= 2 * MAX - 1; a++) {
		if ((a * a + 1) % 2 != 0) continue;
		ll c = (a * a + 1) / 2;
		ll b = c - 1;
		if (a * a + b * b == c * c) arr.push_back(c);
	}
	/*cout << arr.back() << ' ' << arr.size() << '\n';
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';*/
	int t; cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n < 5) {
			cout << 0 << '\n';
			continue;
		}

		// arr[lo] <= x < arr[hi]
		ll lo = -1, hi = arr.size();
		int ans = 0;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;
			if (arr[mid] <= n) {
				lo = mid;
			}
			else {
				hi = mid;
			}
		}
		cout << lo + 1 << '\n';
		//cout << (arr[lo] <= n ? lo + 1 : lo) << '\n';
	}

	return 0;
}