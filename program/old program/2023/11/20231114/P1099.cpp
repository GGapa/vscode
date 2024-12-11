/**
 * @Problem      : P1099 [NOIP2007 提高组] 树网的核
 * @URL          : https://www.luogu.com.cn/problem/P1099
 * @Author       : GGapa
 * @Date         : 2023-11-14 11:17:37
 * @LastEditTime : 2023-11-15 09:23:10
**/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 500;

int n, s;
int ans = 2e9, far, dis[maxn], fa[maxn];
vector<pair<int, int> > G[maxn];
bool flag[maxn];

void dfs(int x, int f) {
    fa[x] = f;
    if(dis[x] > dis[far]) far = x;
    for(auto i : G[x]) {
        int to = i.first, w = i.second;
        if(to == f || flag[to]) continue;
        dis[to] = dis[x] + w;
        dfs(to, x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> s;
    for(int i = 1, u, v, w;  i< n; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    int A, B;
    dis[1] = 1; dfs(1, 0); A = far;
    dis[far] = 0, dfs(far, 0); B = far;
    for(int i = B, j = B; i; i = fa[i]) {
        while(dis[j] - dis[i] > s) j = fa[j];
        int x = max(dis[B] - dis[j], dis[i]);
        ans = min(ans, x);
    }
    for(int i = B; i; i = fa[i]) flag[i] = true;
    for(int i = B; i; i = fa[i]) {
        dis[i] = 0;
        dfs(i, fa[i]);
    }
    for(int i = 1; i <= n; i++) ans = max(ans, dis[i]);
    cout << ans << '\n';
    return 0;
}