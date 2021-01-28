#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define ll long long

bool isYes[100];

void makeTable(int d) {
	for (int i = d; i < 100; i += 10) {
		isYes[i] = true;
		for (int j = d; j < 100; j++) {
			if (isYes[j] && j + i < 100) {
				isYes[j + i] = true;
			}
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int q, d;
		cin >> q >> d;
		vector<ll> a(q);
		for (auto& x : a) { cin >> x; }

		makeTable(d);
		for (auto& x : a) {
			if (d == 1 || (d == 2 && x % 2 == 0)) { cout << "YES\n"; }
			else if (x >= d * 10) { cout << "YES\n"; }
			else if (isYes[x]) {
				cout << "YES\n";
			}
			else { cout << "NO\n"; }
		}
		memset(isYes, 0, sizeof(isYes));
	}

	return 0;
}