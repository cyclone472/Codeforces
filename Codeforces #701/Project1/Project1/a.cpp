#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		int ans = 123456789;
		for (int i = 0; i < ans; i++) {
			if (b == 1 && i == 0)
				continue;

			int tmpa = a, tmpb = b + i;
			int cnt = i;
			while (tmpa != 0) {
				tmpa /= tmpb;
				cnt++;
			}
			ans = min(ans, cnt);
		}
		cout << ans << '\n';
	}

	return 0;
}