/*
P1294 欧几里德的游戏
https://www.luogu.com.cn/problem/P1294
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 30;
//#define int long long

struct harr {
    int to, len;
};

vector<harr> G[maxn];
int n, m;
bool used[maxn];
int ans = 0;

bool check() {
    for(int i = 1; i <= n; i++) 
        if(!used[i]) return false;
    return true;
}

void dfs(int x, int val) {
    ans = max(ans, val);
    for(auto to : G[x]) {
        if(!used[to.to]) {
            used[to.to] = true;
            dfs(to.to, val + to.len);
            used[to.to] = false;
        }
    }
}

void addedge(int u, int v, int w) {
    G[u].push_back((harr){v, w});
    G[v].push_back((harr){u, w});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    for(int i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        used[i] = true;
        dfs(i, 0);
    }
    cout << ans << endl;
    return 0;
}