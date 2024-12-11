#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using ULL = unsigned long long;
const int N = 1e6 + 5;

ULL A[N];
vector<ULL> H;
mt19937_64 rd(random_device{}());

vector<int> G[N];
int si[N]; 
void dfs(int x, int fa) {
    si[x] = 1; H[x] = A[0];
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        si[x] += si[to];
        H[x] += H[to] ^ A[si[to]];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    rep(i, 0, N - 1) A[i] = rd();
    int n; cin >> n;
    H.assign(n + 1, 0);
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    dfs(1, 0);
    sort(H.begin() + 1, H.end());
    int t = unique(H.begin() + 1, H.end()) - H.begin() - 1;
    cout << t << '\n';
    return 0;
}
/*
4 
4 0 1 2 3 
4 0 1 1 2 
4 2 0 2 3 
4 0 1 1 1
*/