#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    int p, m;  cin >> p >> m;
    int mn = min(p, m);

    vector<VI> pos(n + 1);
    vector<int> sum(n + 1), que(n + 1);
    pos[0].emplace_back(0);
    rep(i, 1, n) {
        sum[i] = sum[i - 1] + (s[i] == '(') - (s[i] == ')');
        que[i] = que[i - 1] + (s[i] == '?');
        if(s[i] == '?') pos[sum[i]].emplace_back(i);
    }

    int idx = 0;
    using AI = array<int, 3>;
    vector<array<int, 3>> tr(2 * n + 1);
    vector<int> l(n + 1), r(n + 1);
    vector<VI> F(n + 1, VI(1, -1e9)), G(n + 1, VI(1, 1e9));
    
    function<int(int, int)> build = [&](int L, int R) {
        int x = ++idx;
        tr[x] = {L, R};
        if(L == R) return F[x][0] = G[x][0] = s[L] - '0', x;
        
        int it = *prev(lower_bound(pos[sum[L]].begin(), pos[sum[L]].end(), R));
        tr[x][2] = que[R] - que[L - 1];
        l[x] = build(L + (s[L] == '('), it - 1);
        r[x] = build(it + 1, R - (s[R] == ')'));
        return x;
    };
    build(1, n);

    if(p <= m) {
        function<void(int)> dfs = [&](int x) {
            if(tr[x][0] == tr[x][1]) return;
            F[x].assign(tr[x][2] + 1, -1e9);
            G[x].assign(tr[x][2] + 1, 1e9);
            dfs(l[x]); dfs(r[x]);
            rep(i, 0, tr[x][2]) rep(j, 0, tr[l[x]][2])  {
                if(i - j - 1 <= tr[r[x]][2] && i - j - 1 >= 0) {
                    F[x][i] = max(F[x][i], F[l[x]][j] + F[r[x]][i - j - 1]);
                    G[x][i] = min(G[x][i], G[l[x]][j] + G[r[x]][i - j - 1]);
                }
                if(i - j <= tr[r[x]][2] && i - j >= 0) {
                    F[x][i] = max(F[x][i], F[l[x]][j] - G[r[x]][i - j]);
                    G[x][i] = min(G[x][i], G[l[x]][j] - F[r[x]][i - j]);
                }
            }   
        };
        dfs(1);
        cout << F[1][mn] << '\n';
    }
    else {
        function<void(int)> dfs = [&](int x) {
            if(tr[x][0] == tr[x][1]) return;
            F[x].assign(tr[x][2] + 1, -1e9);
            G[x].assign(tr[x][2] + 1, 1e9);
            dfs(l[x]); dfs(r[x]);
            rep(i, 0, tr[x][2]) rep(j, 0, tr[l[x]][2])  {
                if(i - j <= tr[r[x]][2] && i - j >= 0) {
                    F[x][i] = max(F[x][i], F[l[x]][j] + F[r[x]][i - j]);
                    G[x][i] = min(G[x][i], G[l[x]][j] + G[r[x]][i - j]);
                }
                if(i - j - 1 <= tr[r[x]][2] && i - j - 1 >= 0) {
                    F[x][i] = max(F[x][i], F[l[x]][j] - G[r[x]][i - j - 1]);
                    G[x][i] = min(G[x][i], G[l[x]][j] - F[r[x]][i - j - 1]);
                }
            }
        };
        dfs(1);
        cout << F[1][mn] << '\n';
    }
    return 0;
}