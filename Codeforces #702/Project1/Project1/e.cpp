#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> sorta(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sorta[i] = a[i];
			sum += a[i];
		}
		sort(sorta.begin(), sorta.end());

		// 숫자 몇 이상이면 가능한지 알아내서 그 숫자 이상이면 전부 출력
		int minnum = sorta.back();
		for (int i = n - 2; i >= 0; i--) {
			sum -= sorta[i + 1];
			if (sum >= sorta[i + 1]) {
				minnum = sorta[i];
			}
			else {
				break;
			}
		}

		int tot = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= minnum)
				tot++;
		}

		cout << tot << '\n';
		for (int i = 0; i < n; i++) {
			if (a[i] >= minnum)
				cout << i + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}