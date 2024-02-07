#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, x2, y1, y2, r1 = 100, r2 = 0, l1 = 100, l2 = 0;
    rep(i, 1, 2) {
        cin >> x1 >> y1 >> x2 >> y2;
        r1 = min(r1, x1); r2 = max(x2, r2);
        l1 = min(y1, l1); l2 = max(y2, l2);
    }
    int s = max(r2 - r1, l2 - l1);
    cout << s * s << '\n';
    return 0;
}