#include <iostream>
using namespace std;
#define ll long long

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n; cin >> n;
		while (n != 1) {
			if (n % 2 == 0)
				n /= 2;
			else
				break;
		}
		cout << (n == 1 ? "NO\n" : "YES\n");
	}

	return 0;
}