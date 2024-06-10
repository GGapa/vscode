#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5, M = 1e5 + 5;


int n, m;
int ans[M];
int cur[N];
set<pair<int, int>> G[N];
vector<int> G2[N];

int vis[N], in[N];
int cnt = 0, rt, huan = 0;
queue<int> q;
void dfs(int x, int fa) {
    cnt++;
    vis[x] = 1;
    // cout << x << endl;
    for(auto i : G2[x]) if(i != fa) {
        if(vis[i]) {
            huan = 1;
            continue;
        }
        dfs(i, x);    
    }
    if(in[x] >= 3) rt = x;
    if(in[x] % 2) q.push(x);
}

list<int> path;
void work(int x) {
    while(!G[x].empty()) {
        int i = G[x].begin()->first, id = G[x].begin()->second;
        G[i].erase({x, id});
        G[x].erase(G[x].begin());
        work(i);
        path.push_front(id);
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].insert({v, i}), G[v].insert({u, i}), in[v]++, in[u]++, G2[u].emplace_back(v), G2[v].emplace_back(u);
    auto pop = [&](queue<int> &Q) {
        int x = Q.front();
        Q.pop();
        return x;
    };
    rep(c, 1, n) if(!vis[c] && in[c]) {
        cnt = 0; rt = -1; huan = 0;
        while(!q.empty()) q.pop();
        dfs(c, 0);
        // cout << cnt << " " << huan << endl;
        if(rt == -1) {if(cnt % 2 && huan) return cout << "0\n", 0; rt = c;}
        int ls = 1;
        while(!q.size() > 2) {
            int u = pop(q), v = pop(q);
            G[u].insert({v, 0}); G[v].insert({u, 0});
        }


        rt = q.front();
        work(rt); 
        for(auto i : path) {
            ans[i] = ls;
            ls = 3 - ls;
        }
    } 
    rep(i, 1, m) cout << ans[i] << "\n";
    return 0; 
}

/*
对于这种题，考虑在枚举每一条边，来判断是否有解决方案。如果每一条边都直接两种情况判断的话，时间复杂度会很高，待确认。
有可能能够减支的情况特别的多，所以要持有怀疑态度。但暂时还是没有什么头绪，所以先暂时放在一边。
尝试换一种思路，试着使用欧拉路径来解决这道题。
欧拉路径的长度还必须是偶数？
也有可能是判断最大的环，这个环还要是偶数，但也不一定，因为有可能会出现单分支影响答案的情况。
所以说不考虑这一点，应该考虑的是单独的环的大小应该是偶数，否则就可以跑欧拉路径解决问题？
真的吗？
为  了欧拉路径能够跑的正确，应当把奇数点随便弄弄，但是一定要留下来两个奇数点，这是为了防止在计算欧拉路径的时候出锅。
哦！删去的意思是把这个点标记为已使用。
出错了，上一步想错了，如果删边可能会导致更多的奇点出现，所以应当是加边而不是删边。
*/