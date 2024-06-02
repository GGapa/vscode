#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        a = c = 2e9;
        b = d = -2e9;
        int x, y;
        for(int i = 0; i < 4; i++)
          cin >> x >> y, a = min(a, x), b = max(b, x), c = min(c, y), d = max(d, y);
        cout << (b-a)*(d-c) << '\n';
    }
    return 0;
}