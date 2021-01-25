#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b, k;
		cin >> a >> b >> k;
		vector<int> boys(k);
		vector<int> girls(k);
		map<int, int> boyNum, girlNum;
		for (int i = 0; i < k; i++) {
			cin >> boys[i];
			boyNum[boys[i]]++;
		}
		for (int i = 0; i < k; i++) {
			cin >> girls[i];
			girlNum[girls[i]]++;
		}

		ll ans = 0, tot = k;
		for (int i = 0; i < k; i++) {	
			ans += (tot - boyNum[boys[i]] - girlNum[girls[i]] + 1);
			boyNum[boys[i]]--;
			girlNum[girls[i]]--;
			tot--;
			//cout << "CUR: " << ans << '\n';
		}
		cout << ans << '\n';
	}


	return 0;
}