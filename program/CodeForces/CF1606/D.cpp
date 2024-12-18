#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m ;
    vector<VI> A(n + 2, VI(m + 2)), a = A, b = A, c = A, d = A;
    rep(i, 1, n) rep(j, 1, m) cin >> A[i][j];
    vector<int> id(n + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
        return A[x][1] < A[y][1];
    });
    rep(i, 1, n) rep(j, 1, m) { //前缀最大值
        a[i][j] = A[id[i]][j];
        a[i][j] = max({a[i][j], a[i - 1][j], a[i][j - 1]});
    }
    rep(i, 1, n) per(j, m, 1) { //前缀最小值
        b[i][j] = A[id[i]][j];
        if(j < m) b[i][j] = min(b[i][j], b[i][j + 1]);
        if(i > 1) b[i][j] = min(b[i][j], b[i - 1][j]);
    }
    per(i, n, 1) per(j, m, 1) { //后缀最大值
        c[i][j] = A[id[i]][j];
        c[i][j] = max({c[i][j], c[i + 1][j], c[i][j + 1]});
    }
    per(i, n, 1) rep(j, 1, m) { //后缀最小值
        d[i][j] = A[id[i]][j];
        if(j > 1) d[i][j] = min(d[i][j], d[i][j - 1]);
        if(i < n) d[i][j] = min(d[i][j], d[i + 1][j]);
    }
    rep(i, 1, n - 1) rep(j, 1, m - 1) {
        // cout << i << " " << j << " " << a[i][j] << " " << d[i + 1][j] << " " << b[i][j + 1] << " " << c[i + 1][j + 1] << '\n';
        if(a[i][j] < d[i + 1][j] && b[i][j + 1] > c[i + 1][j + 1]) {
            cout << "YES\n";
            // cout << i << " " << j << '\n';
            string ans(n +1, 'R');
            rep(k, 1, i) ans[id[k]] = 'B';
            cout << string(ans.begin() + 1, ans.end()) << ' ' << j << "\n";
            return ;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}