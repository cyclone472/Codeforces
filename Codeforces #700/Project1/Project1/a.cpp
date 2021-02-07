#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;

		string ans = "";
		for (int i = 0; i < s.length(); i++) {
			if (i % 2 == 0) {
				if (s[i] == 'a') ans += 'b';
				else ans += 'a';
			}
			else {
				if (s[i] == 'z') ans += 'y';
				else ans += 'z';
			}
		}
		cout << ans << '\n';
	}

	return 0;
}