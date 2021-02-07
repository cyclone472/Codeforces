#include <iostream>
#include <vector>
using namespace std;

int simulate(vector<int>& h, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (h[i] < h[i + 1]) {
			h[i]++;
			return i + 1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> h(n);
		for (int& x : h) cin >> x;

		bool isFall = false;
		for (int i = 0; i < k - 1; i++) {
			int result = simulate(h, n);
			if (result == -1) {
				isFall = true;
				break;
			}
		}
		cout << simulate(h, n) << '\n';
	}

	return 0;
}