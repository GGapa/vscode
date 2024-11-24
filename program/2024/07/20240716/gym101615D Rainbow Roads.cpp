#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 5e4 + 5;

vector<array<int, 2>> G[N];
int dw[N], up[N], tag[N];
int n;

void dfs1(int x, int fa) {
    set<int> s;
    unordered_map<int, int> it;
    for(auto i : G[x]) {
        int to = i[0], c = i[1];
        if(s.count(c)) {
            if(to == fa) up[fa] = 1, tag[x] = -1;
            else dw[to] = 1;
            if(it[c] == fa) up[fa] = 1, tag[x] = -1;
            else dw[it[c]] = 1;
        }
        else it[c] = to, s.insert(c);
        if(to != fa) dfs1(to, x);
    }
}

void dfs2(int x, int fa) {
    for(auto i : G[x]) if(i[0] != fa) {
        int to = i[0];
        dw[to] += (dw[x]);
        dfs2(to, x);
        up[x] += up[to];
    }
}

void dfs3(int x, int fa) {
    for(auto i : G[x]) if(i[0] != fa) {
        int to = i[0];
        up[to] = (up[x] + tag[to]);
        dfs3(to, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v, w; i < n; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    dfs1(1, 0);
    dfs2(1, 0);
    dfs3(1, 0);
    rep(i ,1, n) cout << up[i] << " \n"[i == n];
    vector<int> ans;
    rep(i ,1, n) if(!dw[i] && !up[i]) ans.emplace_back(i);
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << "\n";
    return 0;
}
/*
8
1 2 1 
2 4 1
2 5 2
1 3 3
3 6 4
8 7 5
7 1 5
*/