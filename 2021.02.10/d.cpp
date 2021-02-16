#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 0이면 빈 공간, 1이면 미네랄이 있음
int map[101][101];
int thr[101];
int caveFloor[101];
int row, col;

void removeOne (int r, int dir) {
    if (dir % 2 == 0) {
        for (int i = 0; i < col; i++) {
            if (map[row-r][i] == 1) {
                map[row-r][i] = 0;
                return;
            }
        }
    }
    else {
        for (int i = col - 1; i >= 0; i--) {
            if (map[row-r][i] == 1) {
                map[row-r][i] = 0;
                return;
            }
        }       
    }
}

void findCluster (vector<vector<int>>& cluster) {
    // 땅에 닿지 않았으면 떨어져야 함
}

// 몇 칸 아래로 떨어져야 하는지를 반환
/* 클러스터의 바닥 배열 */
int fallNum (vector<int> row, vector<int> col) {
    int ret = 10000;
    for (int i = col[0], idx = 0; i <= col.back(); i++, idx++) {
        if (row[idx] )
        ret = min(ret, row[idx] - caveFloor[i]);
    }
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char input;
            cin >> input;
            if (input == '.') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        // 던져서 미네랄 한 개를 없애고
        int thr;
        cin >> thr;
        removeOne(thr, i);

        // bfs로 클러스터들을 탐색
        queue<int> bfs;
        vector<vector<int>> cluster(row, vector<int>(col, 0));
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                if (map[j][k] != 0 && cluster[j][k] == 0) {
                    findCluster(cluster);
                } 
            }
        }
        // 땅
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    // bfs로 클러스터들을 탐색
    // 땅에 닿지 않은 클러스터가 있으면
    // 땅에 닿을 때까지 떨어뜨린다.
    //for (int i = 0; i <)

    return 0;
}