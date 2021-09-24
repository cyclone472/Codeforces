#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

const double INF = -1e15;

int GCD (int x, int y) {
    if (y == 0) return x;
    return GCD(y, x % y);
}

struct Line {
    int x1, y1, x2, y2;
    double gradient;
    Line(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {
        gradient = (x1 == x2 ? INF : (y2-y1)/(x2-x1));
        if (x2 < x1 || (x1 == x2 && y2 < y1)) {swap(x1, x2); swap(y1, y2); }
    } 
};

int parent[3001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) parent[pv] = pu;
}

bool isGrouped(Line& u, Line& v) {
    int x1 = u.x1, x2 = u.x2, y1 = u.y1, y2 = u.y2;
    int x3 = v.x1, x4 = v.x2, y3 = v.y1, y4 = v.y2;
    int A1 = x2 - x1, A2 = y2 - y1;
    int B1 = x4 - x3, B2 = y4 - y3;

    int t = B2*(x3-x1) - B1*(y3-y1);
    int k = A1*(y1-y3) - A2*(x1-x3);
    int D = A1*B2-A2*B1;
    if (D < 0) { t = -t, k = -k, D = -D; }
    if (D == 0) {
        // 두 선분이 평행한 경우
        if (A1*(y3-y1) != A2*(x3-x1)) return false;
        // 두 선분이 일직선 상에 있는 경우
        else if (u.gradient > 0.0) {
            return !((x2 < x3 && y2 < y3) || (x4 < x1 && y4 < y1));
        }
        else if (u.gradient == 0.0) {
            return !(x2 < x3 || x4 < x1);
        }
        else if (u.gradient == INF) {
            return !(y2 < y3 || y4 < y1);
        }
        else {
            return !((x2 < x3 && y2 > y3) || (x4 < x1 && y4 > y1));
        }
    }
    return 0 <= t && t <= D && 0 <= k && k <= D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0;i<3001;i++) parent[i] = i;

    int n; cin >> n;
    vector<Line> lines;
    for (int i=0;i<n;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back({x1, y1, x2, y2});
    }
    
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (isGrouped(lines[i], lines[j])) {
                merge(i, j);
            }
        }
    }
    
    // parent의 index, group size
    map<int, int> groups;
    for (int i=0;i<n;i++) {
        int pi = find(i);
        groups[pi]++;
    }

    int MAX = 0;
    for (auto it=groups.begin();it!=groups.end();it++) {
        MAX = (MAX < it->second ? it->second : MAX);
    }
    cout << groups.size() << '\n' << MAX << '\n';

    return 0;
}