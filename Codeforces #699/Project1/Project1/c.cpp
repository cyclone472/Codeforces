#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> init(n), desired(n), painter(m);
		// map[5] = {1, 3, 4}는 5를 칠해야 하는 널판지가 1, 3, 4 index에 있음을 의미
		map<int, vector<int>> must, all;
		int need = 0;
		for (int& x : init) cin >> x;
		for (int i = 0; i < n; i++) {
			cin >> desired[i];
			all[desired[i]].push_back(i);
			if (init[i] != desired[i]) {
				need++;
				must[desired[i]].push_back(i);
			}
		}
		for (int& x : painter) cin >> x;

		if (all.find(painter.back()) == all.end()) {
			cout << "NO\n";
		}
		else {
			vector<int> ans;
			int repaint = all[painter.back()].front() + 1;
			for (int i = 0; i < m - 1; i++) {
				// i번째 painter가 칠해야 하는 색상이 desire에 있으면 색칠
				if (must.find(painter[i]) != must.end() && !must[painter[i]].empty()) {
					int idx = must[painter[i]].back();
					must[painter[i]].pop_back();
					ans.push_back(idx + 1);
					need--;
				}
				else {
					ans.push_back(repaint);
				}
			}
			// 맨 마지막 원소를 칠해줌
			ans.push_back(repaint);
			for (int x : must[painter.back()]) {
				if (x == repaint - 1) {
					need--;
					break;
				}
			}

			if (need <= 0) {
				cout << "YES\n";
				for (int x : ans) cout << x << ' ';
				cout << '\n';
			}
			else {
				cout << "NO\n";
			}
		}
	}


	return 0;
}