#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 3e5 + 5;

int n, m, k;
int fa[N];
unordered_map<int, int> G[N];
queue<AI<2>> q;

int find(int x) {
    while(x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

template<typename T> 
void clear(T &x) {
    T tmp;
    swap(tmp, x);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return ;
    if(G[x].size() < G[y].size()) swap(x, y);
    for(auto [a, b] : G[y]) {
        // cerr << x << " " << a << " " << b << " " << y << '\n';
        if(G[x].count(a)) {
            q.push({G[x][a], b});
            // merge(G[x][a], b);
        }
        else G[x][a] = b;
    }
    fa[y] = x;
    clear(G[y]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    iota(fa, fa + 1 + n, 0);
    
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> v >> u >> w;
        if(G[u].count(w)) q.push({G[u][w], v});
        else G[u][w] = v;
    }

    cerr << "INIT success!\n";

    while(!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        merge(a, b);
    }

    vector<int> cnt(n + 1);
    rep(i, 1, n) cnt[find(i)]++;
    
    rep(i, 1, n) cerr << cnt[i] << " \n"[i == n];
    LL ans = 0;
    rep(i, 1, n) ans += (cnt[i] * 1ll * (cnt[i] - 1) / 2);
    cout << ans << '\n';

    return 0;
}
/*
6 5
1 6
3 6
3 4
*/