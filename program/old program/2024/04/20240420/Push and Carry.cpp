// Push and Carry
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

ll dis(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc) {
    ll res = abs(xa - xb) + abs(ya - yb);
    if (xa == xb && xb == xc && ((ya < yc && yb > yc) || (ya > yc && yb < yc))) res += 2;
    if (ya == yb && yb == yc && ((xa < xc && xb > xc) || (xa > xc && xb < xc))) res += 2;
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int X = 0, Y = 0;
    X = (xc < xb) - (xc > xb);
    Y = (yc < yb) - (yc > yb);
    if (X == 0) cout << dis(xa, ya, xb, yb + Y, xb, yb) + abs(yb - yc);
    else if (Y == 0) cout << dis(xa, ya, xb + X, yb, xb, yb) + abs(xb - xc);
    else cout << min(dis(xa, ya, xb, yb + Y, xb, yb), dis(xa, ya, xb + X, yb, xb, yb)) + abs(yb - yc) + abs(xb - xc) + 2;
    return 0;
}