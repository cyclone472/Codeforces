#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
	vector<ll> cube;
	for (ll i = 1; i < 10001; i++) {
		cube.push_back(i * i * i);
	}

	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;

		bool ansExist = false;
		for (ll i = 1; i * i * i < x; i++) {
			ll y = x - i * i * i;
			//cout << "y : " << y << ", ";
			// cube[lo] <= y < cube[hi]
			int lo = -1, hi = cube.size();
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (cube[mid] <= y)
					lo = mid;
				else
					hi = mid;
			}
			//cout << "lo : " << lo << ", cube[lo] : " << cube[lo] << '\n';
			if (cube[lo] == y) {
				ansExist = true;
				break;
			}
		}
		cout << (ansExist ? "YES\n" : "NO\n");
	}

	return 0;
}