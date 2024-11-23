#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

int n, m; 

array<int, 2> sx[N], sy[N], px[N], py[N];
vector<int> X, Y;

bool c1(int i, int j) {
    if(i == 1 || j == 1) return true;
    auto xx = px[i - 1], yy = py[j - 1];
    if(X[xx[0]] < Y[yy[0]]) return c1(xx[0], j);
    if(X[xx[1]] < Y[yy[1]]) return c1(i, yy[1]);
    return false;
}

bool c2(int i, int j) {
    if(i == n || j == m) return true;
    auto xx = sx[i + 1], yy = sy[j + 1];
    if(X[xx[0]] < Y[yy[0]]) return c2(xx[0], j);
    if(X[xx[1]] < Y[yy[1]]) return c2(i, yy[1]);
    return false;
}

bool solve(const vector<int> &x, const vector<int> &y) {
    n = x.size() - 1, m = y.size() - 1;
    if(x[1] >= y[1]) return false;  
    
    auto updatex = [&](array<int, 2> &a, int i) {  
        return array<int, 2>{x[a[0]] < x[i] ? a[0] : i, x[a[1]] > x[i] ? a[1] : i};
    };
    auto updatey = [&](array<int, 2> &a, int i) {  
        return array<int, 2>{y[a[0]] < y[i] ? a[0] : i, y[a[1]] > y[i] ? a[1] : i};
    };

    px[1] = py[1] = {1, 1};
    sx[n] = {n, n}; sy[m] = {m, m};
    rep(i, 2, n) px[i] = updatex(px[i - 1], i);
    rep(i, 2, m) py[i] = updatey(py[i - 1], i);
    per(i, n - 1, 1) sx[i] = updatex(sx[i + 1], i);
    per(i, m - 1, 1) sy[i] = updatey(sy[i + 1], i);

    auto xx = px[n], yy = py[m];
    if(x[xx[0]] >= y[yy[0]] || x[xx[1]] >= y[yy[1]]) return false;
    X = x, Y = y;
    return c1(xx[0], yy[1]) && c2(xx[0], yy[1]);
}

signed main() {
    //  freopen("test.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1), x(n + 1), y(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    x = a, y = b;
    cout << (solve(a, b) || solve(b, a) ? "1" : "0");
    for(int kx, ky; q--; ) {
        cin >> kx >> ky;
        a = x, b = y;
        for(int i = 1, it, v; i <= kx; i++) cin >> it >> v, a[it] = v;
        for(int i = 1, it, v; i <= ky; i++) cin >> it >> v, b[it] = v;
        if(q == 52) 
            q++, q--;
        cout << (solve(a, b) || solve(b, a) ? "1" : "0");
    }
    return 0;
}
