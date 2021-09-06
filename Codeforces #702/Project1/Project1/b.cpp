#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAns(int c0, int c1, int c2) {
	if (c0 == c1 && c1 == c2)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int c0 = 0, c1 = 0, c2 = 0;
		for (int& x : a) {
			cin >> x;
			if (x % 3 == 0) c0++;
			else if (x % 3 == 1) c1++;
			else c2++;
		}

		int turn = 0;
		int ans = 0;
		while (!isAns(c0, c1, c2)) {
			if (turn == 0 && c0 > n / 3) {
				ans += (c0 - n / 3);
				c1 += (c0 - n / 3);
				c0 = n / 3;
			}
			else if (turn == 1 && c1 > n / 3) {
				ans += (c1 - n / 3);
				c2 += (c1 - n / 3);
				c1 = n / 3;
			}
			else if (turn == 2 && c2 > n / 3) {
				ans += (c2 - n / 3);
				c0 += (c2 - n / 3);
				c2 = n / 3;
			}
			//cout << c0 << ' ' << c1 << ' ' << c2 << '\n';
			turn = (turn + 1) % 3;
		}
		cout << ans << '\n';
	}
	
	return 0;
}