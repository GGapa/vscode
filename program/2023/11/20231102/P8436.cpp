#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 5e5 + 5;

int n, m, cnt = 0;
vector<pair<int, int> > G[maxn];
vector<int> ans[maxn];
int dfn[maxn], low[maxn];
stack<int> stk;

void tarjan(int x, int fa) {
    low[x] = dfn[x] = ++dfn[0];
        stk.push(x);
    for(auto i : G[x]) {
        int to = i.first, it = i.second;    
        if (it == (fa ^ 1)) continue;   //在这里是为了去重
        if(!dfn[to]) {
            tarjan(to, it);
            low[x] = min(low[x], low[to]);
        }
        else low[x] = min(low[x], dfn[to]);
    }
    if(dfn[x] == low[x]) {
        cnt++;
        ans[cnt].push_back(x);
        while(!stk.empty() && stk.top() != x) {ans[cnt].push_back(stk.top()), stk.pop();}
        stk.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(make_pair(v, i * 2));
        G[v].push_back(make_pair(u, i * 2 + 1));
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i, 0);
    }
    cout << cnt << "\n";
    for(int i = 1; i <= cnt; i++) {
        cout << ans[i].size() << " ";
        for(auto j : ans[i]) cout << j << " ";
        cout << "\n";
    }

    return 0;
}