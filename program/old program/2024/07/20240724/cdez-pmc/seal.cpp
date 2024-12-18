#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int INF = 1e9;



signed main() {
    freopen("seal.in", "r", stdin);
    freopen("seal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, a, b; cin >> n >> m >> a >> b;
    int all = 0;
    vector<string> A(n + 1), s(a + 1);
    rep(i, 1, n) cin >> A[i], A[i] = " " + A[i];
    rep(i, 1, n) rep(j, 1, m) all += (A[i][j] == 'x');
    rep(i, 1, a) cin >> s[i], s[i] = " " + s[i];   
    vector<pair<int, int>> node;
    int si = 1, sj = 1;
    auto init = [&]() {
        rep(i, 1, a) rep(j, 1, b) if(s[i][j] == 'x') {
            si = i, sj = j;  
            return ;
        } 
    };
    init();
    rep(i, 1, a) rep(j, 1, b) if(s[i][j] == 'x') {
        node.push_back({i - si, j - sj});
    }
    vector<VI> vis(n + 1, VI(m + 1));
    auto check = [&](int x, int y) {
        int cnt = 0;
        for(auto p : node) {
            int i = x + p.first, j = y + p.second;
            if(i < 1 || j < 1 || i > n || j > m) return false;
            if(A[i][j] != 'x' || vis[i][j]) return false;
            vis[i][j] = 1;
        }
        return true;
    };
    rep(i ,1, n) rep(j, 1, m) if(A[i][j] == 'x' && !vis[i][j]) {
        if(!check(i, j)) return cout << "NIE\n", 0;
        all -= node.size();
    }
    if(all) return cout << "NIOE\n", 0;
    cout << "TAK\n";
    return 0;
}
/*
4 4 4 4
.x..
xxx.
xxxx
.xx.
....
.x..
x.x.
.x..

*/