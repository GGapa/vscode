#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using ULL = unsigned long long;
const int N = 1e6 + 5;

ULL A[N], H[N];
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
    int T; cin >> T;
    map<vector<ULL>, int> mp;
    rep(i ,1, T) {
        int n; cin >> n;
        rep(i, 0, n) vector<int>(0).swap(G[i]);
        for(int i = 1, x; i <= n; i++) {
            cin >> x;
            if(x == 0) continue;
            G[x].push_back(i), G[i].push_back(x);
        }
        vector<ULL> t(1);
        rep(i, 1, n) {
            fill(H, H + 1 + n, 0); fill(si, si + 1 + n, 0);
            dfs(i, 0);
            t.push_back(H[i]);
        }
        sort(t.begin(), t.end()) ;
        if(mp.count(t)) mp[t] = min(mp[t], i);
        else mp[t] = i;
        cout << mp[t] << '\n';
    }
    return 0;
}
/*
4 
4 0 1 2 3 
4 0 1 1 2 
4 2 0 2 3 
4 0 1 1 1
*/