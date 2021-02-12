#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

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
    int n = cluster[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cluster[i][j] << ' ';
        }
    }
}

int fallNum (vector<int> row, vector<int> col) {
    int ret = 10000;
    for (int i = col[0], idx = 0; i <= col.back(); i++, idx++) {
        ret = min(ret, row[idx] - caveFloor[i]);
    }

    return ret;
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
        // ������ �̳׶� �� ���� ���ְ�
        int thr;
        cin >> thr;
        removeOne(thr, i);

        // bfs�� Ŭ�����͵��� Ž��
        queue<int> bfs;
        vector<vector<int>> cluster(row, vector<int>(col, 0));
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                if (map[j][k] != 0 && cluster[j][k] == 0) {
                    findCluster(cluster);
                } 
            }
        }
        // ��
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    // bfs�� Ŭ�����͵��� Ž��
    // ���� ���� ���� Ŭ�����Ͱ� ������
    // ���� ���� ������ ����߸���.
    //for (int i = 0; i <)

    return 0;
}