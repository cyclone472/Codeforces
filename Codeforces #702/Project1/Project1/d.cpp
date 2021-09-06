#include <iostream>
#include <string.h>
using namespace std;

int a[101];
int depth[101];

void getDepth(int lefts, int lefte, int rights, int righte) {
	if (lefts <= lefte) {
		int maxIdx = lefts;
		for (int i = lefts; i <= lefte; i++) {
			depth[i]++;
			if (a[i] > a[maxIdx])
				maxIdx = i;
		}
		getDepth(lefts, maxIdx - 1, maxIdx + 1, lefte);
	}
	if (rights <= righte) {
		int maxIdx = rights;
		for (int i = rights; i <= righte; i++) {
			depth[i]++;
			if (a[i] > a[maxIdx])
				maxIdx = i;
		}
		getDepth(rights, maxIdx - 1, maxIdx + 1, righte);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(depth, 0, sizeof(depth));
		int n;
		cin >> n;
		int root = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == n)
				root = i;
		}

		// 만약 루트가 0이면?
		getDepth(0, root - 1, root + 1, n - 1);
		for (int i = 0; i < n; i++) {
			cout << depth[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}