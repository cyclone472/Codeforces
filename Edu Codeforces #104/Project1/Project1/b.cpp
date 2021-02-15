#include <iostream>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		if (n % 2 == 0)
			cout << ((k - 1) % n) + 1 << '\n';
		else {
			ll newK = (ll)k + (k - 1) / (n/2);
			cout << ((newK - 1) % n) + 1 << '\n';
		}
	}
	return 0;
}