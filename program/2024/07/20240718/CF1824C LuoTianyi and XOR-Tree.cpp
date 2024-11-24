#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5;

int n;
int A[N];
vector<int> G[N];
map<int, int> mp[N];
int ans = 0;

void dfs(int x, int fa) {
    if(G[x].size() == 1 && fa) {
        mp[x][A[x]] = 1;
        return ;
    }
    int it = -1;
    auto &a = mp[x];
    for(auto to : G[x]) if(to != fa) {
        A[to] ^= A[x];
        dfs(to, x);
        auto &b = mp[to];
        if(a.size() < b.size()) swap(a, b);
        for(auto p : b) {
            a[p.first] += p.second;
            if(it == -1 || a[p.first] > a[it]) it = p.first;
        }
    }
    ans += G[x].size() - (it == -1 ? 1 : a[it]) - (fa != 0);
    if(it != -1 && a[it] > 1) {
        map<int, int> tmp;
        for(auto p : a) if(p.second == a[it]) tmp[p.first] = 1;
        swap(tmp, a);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i ,1, n) cin >> A[i];
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs(1, 0);
    cout << ans + !mp[1][0] << '\n';
    return 0;
}