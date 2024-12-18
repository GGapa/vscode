// P5908 猫猫和企鹅
// https://www.luogu.com.cn/problem/P5908
// 2023-11-14 10:45
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

int n, d, ans;
vector<int> G[maxn];
void dfs(int x, int fa, int dis) {
    ans++;
    if(dis >= d) return ;
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs(to, x, dis+1);
    }
}


int main() {
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, 0);
    cout << ans - 1<< '\n';
    return 0;
}