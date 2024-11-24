#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<LL>;
const LL INF = 1e18;
const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<VI> F(n + 1, VI(m + 1, INF)), G(n + 1, VI(m + 1));
    vector<int> A(n + 1), B(m + 1);
    vector<LL> S(n + 1), cnt(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    rep(i, 1, m) cin >> B[i];
    F[0][1] = 0; G[0][1] = 1;
    vector<unordered_map<LL, int>> mp(m + 1);
    rep(j, 1, m) {
        int k = 0;
        rep(i, 0, n)  {
            while(S[i] - S[k] > B[j]) mp[j][F[k][j]] = (mp[j][F[k][j]] - G[k][j] + mod) % mod, k++;
            if(i != n) {
                if(F[i][j] > F[i][j - 1]) F[i][j] = F[i][j - 1], G[i][j] = G[i][j - 1];
                else if(F[i][j] == F[i][j - 1]) (G[i][j] += G[i][j - 1]) %= mod;
            }

            int t = lower_bound(S.begin(), S.end(), S[i] - B[j]) - S.begin();
            if(t != i)  {
                if(F[i][j] > F[t][j] + m - j) F[i][j] = F[t][j] + m - j, G[i][j] = mp[j][F[t][j]];
                else if(F[i][j] == F[t][j] + m - j) (G[i][j] += mp[j][F[t][j]]) %= mod;
            }
            (mp[j][F[i][j]] += G[i][j]) %= mod;
        }
    }
    LL mn = *min_element(F[n].begin(), F[n].end()), ans = 0;
    if(mn >= INF) return cout << -1 << '\n', void();
    rep(i, 1, m) if(F[n][i] == mn) (ans += G[n][i]) %= mod;
    cout << mn << " " << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}