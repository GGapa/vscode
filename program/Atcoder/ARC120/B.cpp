#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<string> A(n + 1);
    rep(i, 1, n) cin >> A[i], A[i] = " " + A[i];

    LL ans = 1;
    rep(i, 2, n + m) {
        int c1 = 0, c2 = 0, cnt = 0;
        for(int x = max(1, i - m), y; (y = i - x) <= m && y >= 1 && x <= n; x++, cnt++) {
            if(A[x][y] == 'R') c1++;
            if(A[x][y] == 'B') c2++;
        }
        if(c1 && c2) ans = 0;
        if(c1 == 0 && c2 == 0) (ans *= 2) %= mod; 
    }
    cout << ans << '\n';

    return 0;
}