#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		ll heroAtk, heroHP;
		int n;
		cin >> heroAtk >> heroHP >> n;
		vector<pair<ll, ll>> monster(n, make_pair(0, 0));
		// first : attack, second : HP
		for (auto& x : monster) cin >> x.first;
		for (auto& x : monster) cin >> x.second;
		sort(monster.begin(), monster.end());

		bool canWin = true;
		for (int i = 0; i < n - 1; i++) {
			ll fightNum = (monster[i].second + (heroAtk - 1)) / heroAtk;
			heroHP -= fightNum * monster[i].first;
			if (heroHP <= 0) {
				canWin = false;
				break;
			}
		}
		if (canWin && ((monster[n-1].second + (heroAtk - 1)) / heroAtk >
			(heroHP + (monster[n-1].first - 1)) / monster[n-1].first)) {
			canWin = false;
		}

		cout << (canWin ? "YES\n" : "NO\n");
	}

	return 0;
}