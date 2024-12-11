#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int INF = 1e9;

struct Mat {
    int n; 
    vector<VI> A;
    vector<int>& operator [](int i)  {return A[i];} 
    const vector<int>& operator [](int i) const { return A[i]; }
    Mat(int _n) : n(_n) {A.assign(n + 1, VI(n + 1, INF)); }
    const Mat operator*(const Mat &B) const {
        Mat C(n);
        rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) 
             C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
        return C;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t, s, e; cin >> n >> t >> s >> e;
    vector<array<int, 3>> E;
    map<int, int> mp;
    for(int i = 1, u, v, w; i <= t; i++) 
        cin >> w >> u >> v, E.push_back({u, v, w}), mp[u] = 0, mp[v] = 0;
    int cnt = 0;
    for(auto &i : mp) i.second = ++cnt;
    Mat ans(cnt), base(cnt);
    rep(i, 0, cnt) rep(j, 0, cnt) base[i][j] = INF;
    rep(i, 1, cnt) ans[i][i] = 0;
    for(auto i : E) {
        i[0] = mp[i[0]]; i[1] = mp[i[1]];
        base[i[0]][i[1]] = base[i[1]][i[0]] = i[2];
    }
    // n--;
    while(n) {
        if(n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    cout << ans[mp[s]][mp[e]] << '\n';
    return 0;
}