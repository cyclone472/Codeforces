#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int tmp[200001];

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp[i];
		}

		vector<int> b1, b2;
		for (int i = 0; i < n; i++) {
			int b;
			cin >> b;
			if (b == 1)
				b1.push_back(tmp[i]);
			else
				b2.push_back(tmp[i]);
		}
		if (b1.size() % 2 != 0)
			b1.push_back(0);

		sort(b1.begin(), b1.end(), greater<int>());
		sort(b2.begin(), b2.end(), greater<int>());

		int p1 = 0, p2 = 0;
		ll ans = 0;
		for (int i = 0; i < n && p2 < b2.size() && p1 < b1.size(); i++) {
			cout << "HIHI, i is : " << i << "\n";
			if (m - b1[p1] <= 0) {
				ans += 1;
				m -= b1[p1++];
			}
			else if (b1[p1] + b1[p1 + 1] >= b2[p2]) {
				ans += 2;
				m -= b1[p1] + b1[p1 + 1];
				i++;
				p1 += 2;
			}
			else {
				ans += 2;
				m -= b2[p2++];
			}

			if (m <= 0)
				break;
		}
		cout << "HIHI2\n";
		if (m > 0) {
			if (p2 >= b2.size() && p1 < b1.size()) {
				while (p1 < b1.size()) {
					ans += 1;
					m -= b1[p1++];
					if (m <= 0)
						break;
				}
			}
			else if (p2 < b2.size() && p1 >= b1.size()) {
				while (p2 < b2.size()) {
					ans += 2;
					m -= b2[p2++];
					if (m <= 0)
						break;
				}
			}
		}

		cout << (m <= 0 ? ans : -1) << '\n';
	}

	return 0;
}