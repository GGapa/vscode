#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 5;
int CLCOC = clock();

vector<int> G[N];
int vis[N], v[N]; 
int n, sum = 0, k; 

namespace sub12 {
    bitset<4002> F[2001], tmp;
    int si[N], ct[N]; 
    void dfs(int x, int fa) {
        si[x] = v[x]; 
        F[x][v[x]] = 1;
        
        for(auto to : G[x]) if(to != fa) {
            dfs(to, x);
            tmp = F[x];         // debug 赋值应该在搜索之后
            si[x] += si[to];
            rep(j, 0, si[to]) if(F[to][j]) 
                F[x] |= tmp << j;
            ct[x] += ct[to];
        }
        if(F[x][k]) {
            rep(j, 0, si[x]) F[x][j] = 0;
            si[x] = 0, ct[x]++;
        }
    }
    void solve() {
        rep(i, 0, n) rep(j, 0, k) F[i][j] = 0;
        fill(ct, ct + 1 + n, 0); fill(si, si + 1 + n, 0);

        dfs(1, 0);
        cout << ct[1] << '\n'; 
    }
};

namespace sub3 {
    int twtwtw = 0;
    void solve(int st) {
        int ans = 0, ss = 0;
        for(int l = 1, r = 0; r <= n; ss += v[++r]) {       // 警钟敲烂，以后写双指针的时候千万不要写两个动端点，一定要“固定”一个端点后移动另一个端点才不容易出错。
            while(ss > k && l <= r) ss -= v[l++];
            if(ss == k) ans++, l = r + 1, ss = 0; 
        }
        // if(++twtwtw % 10000 == 0) cerr << twtwtw << '\n';
        cout << ans << '\n';
    }
}


namespace sub4 {
    int F[N];
    int ans = 0;
    void dfs(int x, int fa) {
        F[x] = v[x];
        for(auto to : G[x]) if(to != fa) {
            dfs(to, x);
            F[x] += F[to];
        }
        // cerr << "FFF\n";
        // rep(i, 1, n) cerr << F[i] << " \n"[i == n];    
        // cerr << '\n';
        if(F[x] >= k) F[x] = 0, ans++;
    }
    void solve() {
        fill(F, F + 1 + n, 0); ans = 0;
        dfs(1, 0);
        cout << ans << '\n';
    }
}

namespace GOOD {
    int F[N][2], GG[N], tmp[2];
    const int INF = 1e9;
    void dfs(int x, int fa) {
        F[x][v[x] % 2] = v[x];
        for(auto to : G[x]) if(to != fa) {
            dfs(to, x);
            tmp[0] = F[x][0], tmp[1] = F[x][1];
            F[x][0] = max({F[to][0] + tmp[0], tmp[1] + F[to][1], tmp[0]});
            F[x][1] = max({F[to][0] + tmp[1], F[to][1] + tmp[0], tmp[1]});
            GG[x] += GG[to];
        }
        // cerr << x << " " << F[x][0] << " " << F[x][1] << '\n';
        if(F[x][k % 2] >= k) F[x][0] = F[x][1] = -INF, GG[x]++;
    }
    void solve() {
        rep(i, 0, n) F[i][0] = F[i][1] = -INF, GG[i] = 0;
        dfs(1, 0);
        cout << GG[1] << '\n';
    }
}

void solve() {
    cin >> n >> k;
    fill(vis, vis + 1 + n, 0);  sum = 0;
    rep(i, 0, n) vector<int>(0).swap(G[i]);

    bool tag = true, t4 = true;
    for(int i = 2, x; i <= n; i++) {
        cin >> x, G[x].emplace_back(i), G[i].emplace_back(x);
        if(x != i - 1) tag = false;
    }
    rep(i, 1, n) {
        cin >> v[i]; 
        if(v[i] > 1) t4 = false;
    }
    sum = accumulate(v + 1, v + 1 + n, 0);
    if(k == 0) return cout << count(v + 1, v + 1 + n, 0) << '\n', void();

    return GOOD::solve();

    
    if(t4) return sub4::solve();
    if(tag) return sub3::solve(1);
    if(n <= 2000) return sub12::solve();

}
signed main() {
    // freopen("tree5.in", "r", stdin);
    // freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    cerr << (CLCOC - clock()) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
/*
捋一下思路，可以发现 1 才是对答案影响最大的点权，所以考虑从 1 开始进行 DFS，分三种情况考虑
首先如果 k = 0 则直接输出 0 个个数即可
否则以 1 为起点进行 DFS，记录下总共的连通块大小，如果没有 1，那么 k 是奇数无解，偶数则直接输出答案即可。
否则开始 DFS，距离大于 k 直接退出，累加答案。 
非常遗憾的是上面的思路假完了，正解应该是个奇怪的。                                          
*/