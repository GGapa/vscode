/*
Nearby Cows
https://vjudge.csgrandeur.cn/contest/584212#problem/G
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;

int n, k;
vector<int> G[maxn];
int val[maxn];
int ans = 0;
bool used[maxn];
int f[maxn][25]; // 剩下的还能跑多少

int dfs(int x, int step) {
    if(step < 0 || used[x]) return 0;
    used[x] = true;
    if(f[x][step] != 0) {
        return f[x][step];
    }
    int tmp;
    for(auto to : G[x]) {
        tmp += dfs(to, step - 1);
    }
    f[x][step] += tmp;
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> val[i], f[i][0] = val[i];
    for(int i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        ans = 0;
        cout << dfs(i, k) << endl;
    }
}