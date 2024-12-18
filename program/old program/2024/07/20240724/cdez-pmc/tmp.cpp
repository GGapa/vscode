#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int INF = 1e9;



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("seal.in", "r", stdin);
    freopen("seal.out", "w", stdout);
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<string> A(n + 1), s(a + 1);
    rep(i, 1, n) cin >> A[i], A[i] = " " + A[i];
    rep(i, 1, a) cin >> s[i], s[i] = " " + s[i];    
    vector<pair<int, int>> node;
    int ul, ur, tl, tr; ul = ur = INF, tl = tr = 0;
    vector<VI> F(a + 1, VI(b  +1)), G(a + 1, VI(b + 1));
    rep(i, 1, a) rep(j, 1, b) if(s[i][j] == 'x') {
        ul = min(ul, i); ur = min(ur, j);
        tl = max(tl, i); tr = max(tr, j);
    }
    rep(i, ul, tl) rep(j, ur, tr) if(s[i][j] == 'x') 
        node.push_back({i - ul, j - ur});
    return 0;
}
/*
 
*/