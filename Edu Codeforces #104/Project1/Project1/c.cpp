#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		
		if (n % 2 != 0) {
			for (int i = 1; i < n; i++) {
				for (int j = i + 1; j <= n; j++) {
					cout << (j - i <= n / 2 ? 1 : -1) << ' ';
				}
			}
		}
		else {
			while (n > 0) {
				cout << 0 << ' ';
				for (int i = 0; i < (n - 1) / 2; i++) {
					cout << 1 << ' ';
				}
				for (int i = 0; i < ((n - 1) / 2) * 2; i++) {
					cout << -1 << ' ';
				}
				for (int i = 0; i < (n - 1) / 2; i++) {
					cout << 1 << ' ';
				}
				n -= 2;
			}
			cout << '\n';
		}
	}

	return 0;
}