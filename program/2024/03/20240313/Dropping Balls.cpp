// Dropping Balls
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T, D, I;
    cin >> T;
    while (T--) {
        cin >> D >> I;
        int k = 1;
        for (int i = 0; i < D - 1; i++)
            if (I % 2) {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else {
                k = k * 2 + 1;
                I /= 2;
            }
        cout << k << '\n';
    }
    return 0;
}
