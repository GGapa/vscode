/**
 * @Problem      : P1656 炸铁路
 * @URL          : https://www.luogu.com.cn/problem/P1656
 * @Author       : GGapa
 * @Date         : 2023-11-15 16:52:18
 * @LastEditTime : 2023-11-15 17:21:30
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200;

int n, m;
vector<int> G[maxn];
int dfn[maxn], low[maxn], cnt;
vector<pair<int, int>> ans;

void dfs(int x, int fa) {
    low[x] = dfn[x] = ++cnt;
    for(auto to : G[x]) {
        if(to == fa || to == x) continue;
        if(!dfn[to]) {
            dfs(to, x);
            low[x] = min(low[x], low[to]);
            if(low[to] > dfn[x])
                ans.push_back(make_pair(min(x, to), max(x, to)));
        }
        else low[x] = min(low[x], dfn[to]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }   
    for(int i = 1; i <= n; i++) if(!dfn[i]) dfs(i, 0);
    sort(ans.begin(), ans.end());
    for(auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;

}