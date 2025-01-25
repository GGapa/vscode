#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e5 + 5;

int n, sum;
int A[N], sz[N], mx[N];
vector<int> G[N];
LL f[N], g[N];

void dfs(int x) {
    sz[x] = A[x];
    for(auto to : G[x]) dfs(to), sz[x] += sz[to], mx[x] = max(mx[x], sz[to]), f[x] += f[to];
    f[x] += 1ll * sz[x] * A[x]; mx[x] = max(mx[x], sum - sz[x]);
}

void dfs1(int x) {
    g[x] += 1ll * (sum - sz[x] + A[x]) * A[x];
    LL cnt = 0;
    for(auto to : G[x]) cnt += f[to] + 1ll * A[x] * sz[to];
    for(auto to : G[x]) g[to] += g[x] + cnt - f[to] - 1ll * A[x] * sz[to], dfs1(to);
}

vector<int> work(const vector<int> &vec) {
    int tp = (1 << (int)vec.size()) - 1;
    vector<int> ret(tp + 1);
    rep(s, 0, tp) rep(i, 0, (int)vec.size() - 1) {
        if(s >> i & 1) ret[s] += vec[i]; 
        else ret[s] -= vec[i];
    }
    sort(ret.begin(), ret.end());
    return ret;
}

LL ans = 0;

void solve(int rt) {
    vector<int> A1, A2; A1.emplace_back(sum - sz[rt]);
    for(auto to : G[rt]) (A1.size() < A2.size() ? A1 : A2).emplace_back(sz[to]);
    int now = sum;
    auto B1 = work(A1), B2 = work(A2);
    for(auto x : B1) {
        auto it = lower_bound(B2.begin(), B2.end(), -x);
        if(it != B2.begin()) now = min(now, abs(x + *prev(it)));
        if(it != B2.end()) now = min(now, abs(x + *it));
    }
    ans = max(ans, 1ll * (sum - A[rt] + now) * (sum - A[rt] - now) / 4 + f[rt] + g[rt] - 1ll * A[rt] * A[rt]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> A[i];
    sum = accumulate(A, A + 1 + n, 0ll);
    for(int i = 2, x; i <= n; i++)
        cin >> x, G[x].emplace_back(i);

    dfs(1), dfs1(1);

    int mn = sum;
    rep(i, 1, n) mn = min(mn, mx[i]);
    rep(i, 1, n) cerr << f[i] << " \n"[i == n];
    rep(i, 1, n) cerr << g[i] << " \n"[i == n];
    rep(i, 1, n) if(mx[i] == mn) solve(i);
    cout << ans - sum << '\n';
    return 0;
}
