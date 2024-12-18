#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 100000 + 5;
int n;

vector<array<int, 2>> G[N];

int T[N * 31][2], idx = 0;
 
void insert(int x) {
    int t = 0;
    per(i, 31, 0) {
        int c = (x >> i) & 1;
        if(!T[t][c]) T[t][c] = ++idx;
        t = T[t][c];
    }
}

int query(int x) {
    int ret = 0, t = 0;
    per(i, 31, 0) {
        int c = (x >> i) & 1;
        if(T[t][!c]) 
            ret += (1 << i), t = T[t][!c];
        else t = T[t][c];
    }
    return ret;
}

vector<int> A;

void dfs(int x, int fa, int val) {
    A.emplace_back(val);
    insert(val);
    for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(to == fa) continue;
        dfs(to, x,val ^ w);
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v, w; i < n; i++)
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    dfs(1, 0, 0);
    int ans = 0;
    for(auto a : A)  ans = max(ans, query(a));
    cout<< ans << '\n';
    return 0;
}