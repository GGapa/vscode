#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int n, m;
vector<int> G[maxn];
int dfn[maxn], low[maxn], in[maxn], home[maxn], idx, vis[maxn];
stack<int> stk;

void tarjan(int x) {
    dfn[x] = low[x] = ++dfn[0];
    vis[x] = true;
    stk.push(x);
    for(auto to : G[x]) {
        if(!dfn[to]) {
            tarjan(to);
            low[x] = min(low[to], low[x]);
        }
        else if(vis[to]) {
            low[x] = min(dfn[to], low[x]);
        }
    }
    if(low[x] == dfn[x]) {
        idx++;
        while(!stk.empty() && stk.top() != x){
            home[stk.top()] = idx;
            vis[stk.top()] = false;
            stk.pop();
        }
        home[stk.top()] = idx;
        vis[stk.top()] = false;
        stk.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        if(u != v)G[u].push_back(v);
    }
    rep(i, 1, n) if(!dfn[i]) tarjan(i);
    rep(x, 1, n) {
        for(auto to : G[x]) {
            if(home[x] != home[to]) 
                in[home[to]]++;
        }
    }
    int ans = 0;
    rep(i, 1, idx) 
        if(in[i] == 0) ans++;
    cout << ans << '\n';

    return 0;
}