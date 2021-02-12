#include <iostream>
using namespace std;
#define ll long long

int arr[100002];
ll prefixSum[100002];

int main() {
	int n, q, k;
	cin >> n >> q >> k;
	arr[0] = 0, arr[n + 1] = k + 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	prefixSum[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefixSum[i] = prefixSum[i - 1] + arr[i + 1] - arr[i - 1] - 2;
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << k - 1 << '\n';
			continue;
		}

		ll ans = prefixSum[r - 1] - prefixSum[l];
		ans += arr[l + 1] - 2;
		ans += (k - arr[r - 1] - 1);
		cout << ans << '\n';
	}
	
	return 0;
}