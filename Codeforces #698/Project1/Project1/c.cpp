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
		sort(d.begin(), d.end(), greater<int>());

		bool ansExist = true;
		for (int i = 0; i < 2 * n; i = i + 2) {
			if (d[i] != d[i + 1]) {
				cout << "case 1\n";
				ansExist = false;
				break;
			}
		}

		vector<ll> interval;
		for (int i = 2; i < 2 * n; i = i + 2) {
			if ((d[i - 2] - d[i]) % (2 * n - i) != 0) {
				ansExist = false;
				cout << "case 2, i is : " << i << "\n";
				break;
			}
			interval.push_back((d[i - 2] - d[i]) / (2 * n - i));
		}

		ll sumInterval = 0;
		ll len = 0;
		for (auto it = interval.rbegin(); it != interval.rend(); it++) {
			len += *it;
			sumInterval += len;
			//cout << "*it : " << *it << " len : " << len << " sumInterval : " << sumInterval << '\n';
		}
		//cout << "sumInterval : " << sumInterval << '\n';

		if (!ansExist || d[2 * n - 1] - 2 * sumInterval == 0 || (d[2 * n - 1] - 2 * sumInterval) % (2 * n) != 0) {
			cout << "NO\n";
		}
		else
			cout << "YES\n";
	}

	return 0;
}