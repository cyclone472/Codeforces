#include <iostream>
#include <vector>
using namespace std;


int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(101, 0);
		for (int i = 0; i < n; i++) {
			int cnt; cin >> cnt;
			a[cnt]++;
		}

		int ans = -1;
		for (int i = 1; i <= 100; i++) {
			if (ans < a[i])
				ans = a[i];
		}
		cout << ans << '\n';
	}

	return 0;
}