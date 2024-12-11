#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 2e5 + 5;

int n, m;
vector<int> G[N];
int A[N], vis[N];
set<int> s;
vector<int> use;

bool work(int ss) {
    using PI = pair<int, int>;
    priority_queue<PI, vector<PI>, greater<PI>> q;
    int dam = 1, cnt = 0;
    q.push({0, ss});
    for(auto a : use) vis[a] = 0;
    vector<int>(0).swap(use);
    vis[ss] = 1; use.push_back(ss);
    while(!q.empty()) {
        int x = q.top().second; q.pop();
        if(A[x] == 0) s.erase(x);
        if(A[x] > cnt) return false;
        cnt++;
        for(auto to : G[x]) if(!vis[to]){
            vis[to] = 1; use.push_back(to);
            q.push({A[to], to});
        }
    }
    return (cnt == n);
}

void solve() {
    s.clear();
    cin >> n >> m;
    rep(i ,1, n) G[i].clear();
    rep(i, 1, n) cin >> A[i];   
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u); 
    rep(i, 1, n) if(A[i] == 0) s.insert(i);
    while(!s.empty()) {
        if(work(*s.begin())) return cout << "YES\n", void();
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}