#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1000 + 5;
constexpr LL INF = 1e18;

LL F[2][N][N][2];
int A[500005], B[500005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, L; cin >> n >> L;
    fill_n(F[0][0][0], N * N * 2 * 2, INF);
    rep(i, 1, n) cin >> A[i], B[A[i]]++;
    int cnt = 0;
    rep(i, 1, L) cnt += (B[i] > 0);
    rep(i, 1, L) B[i] += B[i - 1];
    int q; cin >> q;

    if(cnt >= 1000) {
        while(q--) cout << "No" << '\n';
        return 0;
    }

    sort(A + 1, A + 1 + n);
    n = unique(A + 1, A + 1 + n) - A - 1;

    F[0][1][n][0] = F[1][1][n][1] = 0;
     rep(i, 0, 1) per(len, n - 1, 1)
        for(int l = 1, r; (r = l + len - 1) <= n; l++) {
            int num = B[L] - B[A[r]] + 1;
            if(A[l]) num += B[A[l] - 1];
            F[i][l][r][0] = min({F[i][l][r][0], F[i][l-1][r][0] + 1ll * num * (A[l] - A[l - 1]), F[i][l][r + 1][1] + 1ll * num * (A[r + 1] - A[l])});
            F[i][l][r][1] = min({F[i][l][r][1], F[i][l-1][r][0] + 1ll * num * (A[r] - A[l - 1]), F[i][l][r + 1][1] + 1ll * num * (A[r + 1] - A[r])});
        }
    
    for(int u, v, T; q--; ) {
        cin >> u >> v >> T;
        LL ans = LLONG_MAX;
        int x = lower_bound(A + 1, A + 1 + n, v) - A;
        if(v < A[1]) ans = F[1][1][1][1] + abs(u - A[n]) + 1ll * (B[L] + 1) * (A[1] - v);
        else if(v > A[n]) ans= F[0][n][n][0] + abs(u - A[1]) + 1ll * (B[L] + 1) * (v - A[n]);
        else {
            rep(i, 0, 1) {
                ans = min(ans, F[0][x - i][x - i][0] + abs(u - A[1]) + 1ll * (B[L] + 1) * abs(v - A[x - i]));
                ans = min(ans, F[1][x - i][x - i][1] + abs(u - A[n]) + 1ll * (B[L] + 1) * abs(v - A[x - i]));
            }
        }
        cout << (ans + B[L] <= T ? "Yes" : "No") << '\n';
    }

    return 0;
}