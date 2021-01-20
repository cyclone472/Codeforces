#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>

vector<int>& getPrefix(vector<pii>& friends) {
    vector<int> minPrefix(friends.size()); // index of smallest friends
    minPrefix[0] = 0;
    for (int i = 1; i < friends.size(); i++) {
        pii min = friends[minPrefix[i-1]];
        minPrefix[i] = (friends[i].second < min.second ? i : minPrefix[i-1]);
    }

    return minPrefix;
}

// return : index of target pair
int binarySearch (vector<pii>& arr, pii target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid].first <= target.first)
            lo = mid;
        else
            hi = mid;
    } 
    return lo;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pii> standing(n);
        vector<pii> lying(n);
        for (int i = 0; i < n; i++) {
            int height, width;
            cin >> height >> width;
            standing[i] = make_pair(height, width);
            lying[i] = make_pair(width, height);
        }
        sort(standing.begin(), standing.end());
        sort(lying.begin(), lying.end());

        vector<int> standPrefix = getPrefix(standing);
        vector<int> liePrefix = getPrefix(lying);

        // 1. Find in front of i-th friend (both are standing or lying)
        for (int i = 0; i < )

        for (int i = 0; i < friends.size(); i++) {
            cout << friends[i].first << " / " << friends[i].second << '\n';
        }
    }

    return 0;
}