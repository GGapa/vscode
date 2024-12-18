#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n, m;
vector<pii> G[N];
vector<int> ans;
int s;
bool vis[N], flag;
//图不一定是连通的。没有重边，不包含自环
void dfs(int x, int flag) {
    if(flag) return ;
    if(x == s) {
        flag = true;
        for(auto i : ans) cout << i << " ";
        cout << '\n';
        return ;
    }
    for(auto to : G[x]) {
        if(vis[to.first]) continue;
        ans.push_back(to.first);
        dfs(to.first, flag);
        ans.pop_back();
    }
}

void solve() {
    rep(i, 1, n) G[i].clear();
    ans.clear();
    flag = false;
    memset(vis, 0, sizeof(vis));
    int mn = INT_MAX;
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        if(w < mn) {
            mn = w;
            s = u;
        }
    }
    for(auto to : G[s]) {
        if(!vis[to]) dfs(to, 0);
        if(flag) return;
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
给定一个具有 n 个顶点和 m 条边的无向加权图。图中每对顶点之间最多有一条边，图中不包含环（从一个顶点到自身的边）。图不一定是连通的。

如果图中存在简单环，则称该环为简单环。简单环不重复经过同一顶点，且不包含重复的边。

在这个图中找到最小边权重最小的简单环。

输入
第一行输入一个整数 t（1≤t≤104） —— 测试用例数。接下来是每个测试用例的描述。

每个测试用例的第一行包含两个整数 n 和 m（3≤n≤m≤min(n⋅(n−1)2,2⋅105)） —— 图的大小和边的数量。

测试用例的接下来 m 行包含三个整数 u、v 和 w（1≤u,v≤n，u≠v，1≤w≤106） —— 顶点 u 和 v 由权重为 w 的边连接。

保证每对顶点之间最多有一条边。请注意，在给定的约束条件下，图中始终至少存在一个简单环。

保证所有测试用例中 m 的值的总和不超过 2⋅105。

输出
对于每个测试用例，输出一对数字 b 和 k，其中：

b —— 找到的环中最小边的权重，
k —— 找到的环中的顶点数。
在下一行中，按遍历顺序输出 k 个从 1 到 n 的数字 —— 环的顶点。

请注意，答案总是存在的，因为在给定的约束条件下，图中始终至少存在一个简单环。




*/