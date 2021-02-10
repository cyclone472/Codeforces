#include <iostream>
#include <vector>
using namespace std;

char c[4] = {'R', 'B', 'Y', 'G'};
// color[0] : ������ ī���� ����, color[1] : �Ķ���
// color[2] : ����� ī���� ����, color[3] : ���
int color[4];
int count[10];

int main() {
    vector<pair<char, int>> card(5);
    int maxNum = -1;
    for (int i = 0; i < 5; i++) {
        cin >> card[i].first >> card[i].second;
        maxNum = (maxNum < card[i].second ? card[i].second : maxNum);
    }

    // 1�� ��Ģ
    bool correct = true;
    char color = card[0].first;
    for (int i = 1; i < 5; i++) {
        if (color != card[i].first) {
            correct = false;
            break;
        }
    }
    if (correct) cout << 900 + maxNum << '\n';

    // 2�� ��Ģ

    return 0;
}