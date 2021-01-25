#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool isYes = false;
		for (int i = 0; i < 500; i++) {
			for (int j = 0; j < 500; j++) {
				if (2020 * i + 2021 * j == n) {
					isYes = true;
					break;
				}
			}
		}

		cout << (isYes ? "YES\n" : "NO\n");
	}
	return 0;
}