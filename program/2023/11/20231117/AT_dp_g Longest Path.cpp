/**
 * @Problem      : AT_dp_g Longest Path
 * @URL          : https://www.luogu.com.cn/problem/AT_dp_g
 * @Author       : GGapa
 * @Date         : 2023-11-17 18:01:16
 * @LastEditTime : 2023-11-17 18:14:52
**/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int dp[maxn];

int n, m;
vector<int> G[maxn];

int dfs(int x) {
    if(dp[x]) return dp[x];
    for(auto to : G[x]) {
        dp[x] = max(dfs(to) + 1, dp[x]);
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++)  {
        cin >> u >> v;
        G[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        ans = max(ans, dfs(i));
    cout << ans;
    return 0;
}
//AC 100