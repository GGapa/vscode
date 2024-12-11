// P5116 [USACO18DEC] Mixing Milk B
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 100;
    int a, b, c, x, y, z;
    cin >> a >> x >> b >> y >> c >> z;
    while(T) {
        int t1 = min(x, b - y);
        // T--;
        y += t1;
        x -= t1;
        if(!--T) break;
        // cout << x << " " << y << " " << z << '\n';
        int t2 = min(y, c - z);
        z += t2;
        y -= t2;
        if(!--T) break;
        // cout << x << " " << y << " " << z << '\n';
        int t3 = min(z, a - x);
        x += t3;
        z -= t3;
        if(!--T) break;
        // cout << x << " " << y << " " << z << '\n';
    }
    cout << x << '\n' << y << '\n' << z << '\n';

    return 0;
}