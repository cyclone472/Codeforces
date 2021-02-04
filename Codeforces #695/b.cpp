#include <iostream>
#include <vector>
using namespace std;

int n;

int remove (vector<int>& hv, vector<int>& a, int ans) {
    for (int i = 1; i <= n; i++) {
        if (hv[i] == 1 && hv[i+1] == -1 && hv[i-1] == -1) {
            return ans-3;
        }
        else if (hv[i] == -1 && hv[i+1] == 1 && hv[i-1] == 1) {
            return ans-3;
        }
    }
    bool canRemove = false;
    for (int i = 1; i <= n; i++) {
        // hill + valley
        if (hv[i] == 1 && hv[i+1] == -1) {
            canRemove = true;
            if (a[i-1] <= a[i+1] || a[i] <= a[i+2])
                return ans-2;
            else if (a[i-2] == a[i-1] || a[i+2] == a[i+3])
                return ans-2;
        }
        // valley + hill
        else if (hv[i] == -1 && hv[i+1] == 1) {
            canRemove = true;
            if (a[i-1] >= a[i+1] || a[i] >= a[i+2])
                return ans-2;
            else if (a[i-2] == a[i-1] || a[i+2] == a[i+3])
                return ans-2;
        }
    }
    if (canRemove) return ans-1;

    for (int i = 1; i <= n; i++) {
        if (hv[i] == 1 || hv[i] == -1)
            return ans-1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n+2);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        arr[0] = arr[1];
        arr[n+1] = arr[n];

        vector<int> hv(n+2, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                hv[i] = 1; // Hill
            else if (arr[i] < arr[i-1] && arr[i] < arr[i+1])
                hv[i] = -1; // Valley
            else
                continue;
            ans++;
        }

        cout << remove(hv, arr, ans) << '\n';
    }

    return 0;
}