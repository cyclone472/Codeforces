#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        string red, blue;
        cin >> n >> red >> blue;

        int red_score = 0, blue_score = 0;
        for (int i = 0; i < n; i++) {
            if (red[i] > blue[i]) red_score++;
            else if (red[i] < blue[i]) blue_score++;
        }

        if (red_score > blue_score) cout << "RED\n";
        else if (red_score < blue_score) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }

    return 0;
}