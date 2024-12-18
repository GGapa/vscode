#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5;
constexpr LL INF = 1e9;

LL pw[N];
vector<int> G[N];
int n;
int F[N];

void dfs(int x, int fa) {
    if(G[x].size() == 1 && fa != 0) return ;
    for(auto to : G[x]) if(to != fa) dfs(to, x);
    sort(G[x].begin(), G[x].end(), [&](const int x, const int y) {
        return F[x] > F[y];
    });
    int mx = 0;
    for(auto to : G[x]) if(to != fa) {
        mx = F[to];
        break;
    }
    int ad = 0;
    bool tag = 1;
    while(tag) {
        tag = 0;
        ad++;
        LL hig = ad + mx, cnt = 1;
        for(auto to : G[x]) if(to != fa) {
            cnt = min(INF, pw[hig - F[to]] * cnt);
            hig = F[to];
            cnt--;
            if(cnt < 0) {tag = 1; break; }
        }
    }
    F[x] = ad + mx;
}

void solve() {
    cin >> n;
    fill(F, F + 1 + n, 0);
    rep(i, 1, n) vector<int>(0).swap(G[i]);
    for(int i = 2, x; i <= n; i++) 
        cin >> x, G[x].emplace_back(i), G[i].emplace_back(x);
    dfs(1, 0);
    cout << F[1] << '\n';
}

void init() {
    pw[0] = 1;
    rep(i, 1, N - 1) pw[i] = min(INF, pw[i - 1] * 2);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}