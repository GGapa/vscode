//[NOIP2015 提高组] 神奇的幻方

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n, a[40][40], x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    x = 1, y = (n + 1) / 2;
    rep(i, 1, n * n)  {
        a[x][y] = i;
        if(!a[(x - 2 + n) % n + 1][y % n + 1]) x = (x - 2 + n) % n + 1, y = y % n + 1;
        else x = x % n + 1;
    }
    rep(i, 1, n) {
        rep(j, 1, n)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}