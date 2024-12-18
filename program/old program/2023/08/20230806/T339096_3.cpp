//T339096 『MGOI』Simple Round I | C. 魔法禁林
//https://www.luogu.com.cn/problem/T339096?contestId=101050
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
#define int long long
int n, m, s, t;
const int maxn = 2e4 + 5;
const int maxm = 40000 + 5;
struct S {
    int to, monster, val = -1, dep = 1;
};
vector <S> G[maxn];
int ans = LLONG_MAX;
bool used[maxn];
void dfs(int x, int dep, int S) {
    
    if(s > ans || used[x]) return;
    used[x] = true;
    if(x == s) {
        ans = min(ans, S);
        used[x] = false;
        return ;
    }
    for(int i = 0; i < G[x].size(); i++) {
        
        G[x][i].dep = min(G[x][i].dep, dep);
        G[x][i].val = G[x][i].monster / G[x][i].dep;
        dfs(G[x][i].to, dep + 1, S + G[x][i].val);
    }
    used[x] = false;
}

signed main() {
    cin >> n >> m >> s >> t;
    for(int i = 1, u, v, w;i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back((S){v, w, -1, LLONG_MAX});
        G[v].push_back((S){u, w, -1, LLONG_MAX});  
    }
    dfs(t, 1, 0);
    cout << ans << endl;
    return 0;
}