#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> d(2*n);
		for (auto& x : d) { cin >> x; }
		sort(d.begin(), d.end(), greater<ll>());

		bool ansExist = true;
		for (int i = 0; i < 2 * n; i = i + 2) {
			if (d[i] != d[i + 1]) {
				ansExist = false;
				break;
			}
		}

		vector<ll> interval(n);
		for (int i = 2; i < 2 * n; i = i + 2) {
			if (d[i - 2] == d[i] || (d[i - 2] - d[i]) % (2 * n - i) != 0) {
				ansExist = false;
				break;
			}
			//interval.push_back((d[i - 2] - d[i]) / (2 * n - i));
			interval[i / 2] = (d[i - 2] - d[i]) / (2 * n - i);
		}

		ll first = d[2 * n - 1];
		/*
		cout << "d[i] : ";
		for (auto& x : d) {
			cout << x << ' ';
		} */
		if (ansExist) {
			for (int i = 1; i < n; i++) {
				first -= 2 * i * interval[i];
			}
		}
		/*
		ll sumInterval = 0;
		ll len = 0;
		for (auto it = interval.rbegin(); it != interval.rend(); it++) {
			len += *it;
			sumInterval += len;
		}*/

		if (!ansExist || first <= 0 || first % (2 * n) != 0) {
			cout << "NO\n";
		}
		else
			cout << "YES\n";
	}

	return 0;
}