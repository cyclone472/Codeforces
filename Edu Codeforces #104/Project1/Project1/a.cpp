#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		int min = 10000;
		for (int& x : arr) {
			cin >> x;
			min = (x < min ? x : min);
		}

		int ans = 0;
		for (int& x : arr) {
			if (x == min) ans++;
		}
		cout << n - ans << '\n';
	}
	return 0;
}