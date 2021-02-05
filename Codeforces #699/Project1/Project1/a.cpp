#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		char checkX = (x > 0 ? 'R' : 'L');
		char checkY = (y > 0 ? 'U' : 'D');

		int numX = 0, numY = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == checkX) numX++;
			else if (s[i] == checkY) numY++;
		}
		
		cout << (abs(numX) >= abs(x) && abs(numY) >= abs(y) ? "YES\n" : "NO\n");
	}

	return 0;
}