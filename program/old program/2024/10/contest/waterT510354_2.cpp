#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;
const LL INF = 1e18;

int qwq, n;
vector<int> G[N];
LL A[N], mn[N], mx[N], F[N];
int pa[N];
bool tag = true;

bool check(int x, LL v) {
    LL t = A[x] - v; LL sum = 0;
    for(auto to : G[x]) if(to != pa[x]) 
        sum += max(0ll, A[to] - v);
    return sum <= t;
}

void dfs(int x, int fa) {
    LL l = -INF, r = A[x], ret = 0;
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        l = max(l, mn[to]);
    }
    while(l <= r) {
        LL mid = l + r >> 1;
        if(check(x, mid)) ret = mid, r = mid - 1;
        else l = mid + 1;
    }
    mn[x] = ret; 
}

void dfs2(int x, int fa) {
    mx[x] = A[x];
    LL mm = -INF;
    bool tg = false;
    for(auto to : G[x]) if(to != fa) {
        dfs2(to, x);
        F[x] += F[to];
        mm = max(mm, mx[to]);
    }
    if((mm > A[x] && A[x] <= 0) || (A[x] < F[x] && A[x] >= 0)) tag = false;
    F[x] = max(F[x], A[x]); mx[x] = max(mx[x], A[x]);
}

void solve() {
    cin >> n;
    tag = 1;
    rep(i, 0, n) vector<int>(0).swap(G[i]);
    for(int i = 2, x; i <= n; i++) 
        cin >> x, G[i].emplace_back(x), G[x].emplace_back(i), pa[i] = x;
    rep(i, 1, n) cin >> A[i], mx[i] = mn[i] = -INF, F[i] = 0;
    // dfs(1, 0);
    dfs2(1, 0);
    LL ttt = 0;
    for(auto to : G[1]) ttt += A[to] - mn[to];
    if(tag && ttt >= A[1]) cout << "Huoyu\n";
    else cout << "Shuiniao\n";
}

signed main() {
    freopen("water3.in", "r", stdin);
    freopen("water.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> qwq;
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

/*

1
1
6
1 2 2 4 2
83 69 -99 18 -38 39
*/