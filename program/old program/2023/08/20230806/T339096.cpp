//T339096 『MGOI』Simple Round I | C. 魔法禁林
//https://www.luogu.com.cn/problem/T339096?contestId=101050
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
int n, m, s, t;
const int maxn = 2e4 + 5;
const int maxm = 40000 + 5;
struct S {
    int to, monster, val = -1, dep = INT_MAX;
};
vector <S> G[maxn];
int ans[maxn][4];//标记，长度，深度；

void dfs(int x, int dep) {
    if(dep > 100) return;
    for(int i = 0; i < G[x].size(); i++) {
        if(G[x][i].dep < dep) continue;
        G[x][i].dep = dep;
        dfs(G[x][i].to, dep + 1);
    }
}

void Dij() {
    bool tag = true;
    ans[t][2] = 0;
    ans[t][3] = 1;
    while(tag)
    {
        int minNum = INT_MAX, minIt;
        for(int i = 1; i <= n; i++) {
            if(minNum > ans[i][2] && ans[i][1] == 0) {
                minNum = ans[i][2];
                minIt = i;
            }
        }
        if(minNum == INT_MAX) break;
        ans[minIt][1] = 1;
        for(int i = 0; i < G[minIt].size(); i++) {
            //ans[G[minIt][i].to][3] = ans[minIt][3] + 1;
            G[minIt][i].val = G[minIt][i].monster / G[minIt][i].dep;
            if(ans[minIt][2] + G[minIt][i].val < ans[G[minIt][i].to][2]) {
                ans[G[minIt][i].to][2] = ans[minIt][2] + G[minIt][i].val;
            }
        }
    }
}
signed main() {
    cin >> n >> m >> s >> t;
    for(int i = 1, u, v, w;i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back((S){v, w, -1, INT_MAX});
        G[v].push_back((S){u, w, -1, INT_MAX});  
    }
    dfs(t, 1);
    for(int i = 1; i <= n; i++) {
        ans[i][2] = INT_MAX;
    }
    Dij();
    cout << ans[s][2] << endl;
    return 0;
}