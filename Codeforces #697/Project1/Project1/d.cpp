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
		b1.push_back(0);
		b1.push_back(0);
		b2.push_back(0);

		sort(b1.begin(), b1.end(), greater<int>());
		sort(b2.begin(), b2.end(), greater<int>());

		int p1 = 0, p2 = 0;
		ll ans = 0;
		while(m > 0 && (p1 < b1.size() - 2 || p2 < b2.size() - 1)) {
			if (b1[p1] >= m || (b1[p1] + b1[p1+1] > b2[p2])) {
				ans++;
				m -= b1[p1++];
			}
			else {
				ans += 2;
				m -= b2[p2++];
			}
		}

		cout << (m <= 0 ? ans : -1) << '\n';
	}

	return 0;
}