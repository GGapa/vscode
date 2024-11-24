#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;

int Testnumber;
int F[N][10];
int A[10];

void solve() {
    string s; cin >> s;
    rep(i, 1, 9) cin >> A[i];
    int n = s.size(); s = " " + s;
    memset(F, -1, sizeof(F));
    per(i, n - 1, 0) rep(j, 1, 9) {
        F[i][j] = F[i + 1][j];
        F[i][s[i + 1] - '0'] = i + 1;
    }
    LL ans = LLONG_MAX, ss = 0; 
    rep(i, 1, n) ss += A[s[i] - '0'];
    function<void(int, int, int, LL)> dfs = [&](int x, int i, int now, LL sum) {
        ans = min(ans, now + ss - sum);
        // cerr << now << " " << sum << '\n';
        if(x >= 7) return;
        rep(nt, 1, 9) if(F[i][nt] != -1) 
            dfs(x + 1, F[i][nt], now * 10 + nt, sum + A[nt]);
    };
    dfs(0, 0, 0, 0);
    cout << ans << '\n';
}

signed main() {
    // freopen("bargain4.in", "r", stdin);
    // freopen("bargain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> Testnumber;
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*67
0
1
123
10 10 10 10 10 10 10 10 10 
1111011100101101
3158927982863528
98262

17
1 2 3 3 1 6 2 6 7 6 7 5 7 4 5 4
1085812 1016368 1005935 34732 971203 -2845559 -3302189 -762905 -8763235 -8154558 -3452541 -4770687 381008 -6836586 -4039417 -5433244 -656280
*/