//Number Grid
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y, x;
    cin >> y >> x;
    cout << (x - 1 ^ y - 1) << "\n";
    return 0;
}