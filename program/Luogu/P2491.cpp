#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 3e5 + 6;

int n, s ;
vector<pair<int, int>> G[N];
int dis[N], pre[N], vis[N];

namespace INIT {
    void dfs(int x, int fa) {
        pre[x] = fa;
        for(auto i : G[x]) {
            int to = i.first, w = i.second;
            if(to == fa) continue;
            dis[to] = dis[x] + w;
            dfs(to, x);
        }
    }
    int getep(int x) {
        dfs(x, 0) ;
        int ret = 0;
        rep(i, 1, n) if(dis[i] > dis[ret]) ret = i;
        return ret;
    } 
    vector<int> getd(int x) {
        vector<int> ret;
        for(; x; x = pre[x])  ret.emplace_back(x);
        return ret;
    }
}

void dfs(int x, int fa, vector<int> &mx) {
    for(auto i : G[x]) {
        int to = i.first, w = i.second;
        if(to == fa) continue;
        dfs(to, x, mx);
        mx[x] = max(mx[x], mx[to] + w);
    }
}

int get(int x, vector<int> &mx) {
    int ret = 0;
    for(auto i : G[x]) {
        int to = i.first, w = i.second;
        if(vis[to]) continue;
        ret = max(ret, mx[to] + w) ;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 1, u, v, w; i < n; i++) 
        cin >> u >>     v >> w, G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    int x = INIT::getep(1);
    int y = INIT::getep(x);
    vector<int> d = INIT::getd(y);
    vector<VI> mx(3, VI(n + 1));
    dfs(x, 0, mx[0]); dfs(y, 0, mx[1]);
    for(auto a : d) vis[a] = 1;
    for(auto a : d) mx[2][a] = get(a, mx[1]);

    list<int> q;
    multiset<int> st;
    vector<int> cnt(n + 1);
    int ans = INT_MAX;
    for(auto i : d) {
        q.emplace_back(i);
        st.insert(mx[2][i]);
        while(!q.empty() && abs(dis[q.front()] - dis[q.back()]) > s) {
            st.erase(st.find(mx[2][q.front()])) ;
            q.pop_front();
        }
        if(!q.empty()) ans = min(ans, max({mx[0][q.front()], mx[1][q.back()], *st.rbegin()}));
    }
    cout << ans << '\n';
    return 0;
}