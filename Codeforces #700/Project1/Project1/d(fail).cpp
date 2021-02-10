#include <iostream>
#include <vector>
using namespace std;
const int INF = 123456789;

int arr[100001];

// Test Failed
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    arr[n] = INF;

    vector<int> locate(n + 1, INF), nextIdx(n + 1, INF);
    for (int i = n-1; i >= 0; i--) {
        nextIdx[i] = locate[arr[i]];
        locate[arr[i]] = i;
    }

    //a1, a2에다가 index를 넣으면?
    vector<int> a1(1, n), a2(1, n);
    for (int i = 0; i < n; i++) {
        int a1num = arr[a1.back()], a2num = arr[a2.back()];
        // 다음 숫자가 양쪽 배열과 모두 같으면 그냥 패스
        if (arr[i] == a1num && arr[i] == a2num)
            continue;
        else if (arr[i] != a1num && arr[i] == a2num)
            a1.push_back(i);
        else if (arr[i] == a1num && arr[i] != a2num)
            a2.push_back(i);
        else {
            if (nextIdx[a1.back()] < nextIdx[a2.back()]) {
                a1.push_back(i);
            }
            else
                a2.push_back(i);
        }
    }
    cout << a1.size() + a2.size() - 2 << '\n';

    return 0;
}