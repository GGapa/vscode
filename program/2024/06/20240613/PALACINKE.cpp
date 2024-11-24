#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 50 + 5;
const int mod = 5557;

struct Mat {
    int n; 
    vector<VI> A;
    vector<int>& operator [](int i)  {return A[i];} 
    const vector<int>& operator [](int i) const { return A[i]; }
    Mat(int _n) : n(_n) {A.assign(n + 1, VI(n + 1, 0)); }
    const Mat operator*(const Mat &B) const {
        Mat C(n);
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] += (A[i][k] * B[k][j]) % mod) %= mod;
        return C;
    }
};

int n, m, nn;
unordered_map<char, int> exc;
vector<pair<int, int>> G[N];

int work(int ban, int T) {
    Mat ans(nn), base(nn);
    rep(i, 0, nn) ans[i][i] = 1;
    rep(x, 1, n){
        for(auto i : G[x]) {
            int to = i.first, w = i.second;
            base[x][to] = 1;
            if(ban & w) continue;
            base[x][x + n] = base[x + n][to] = 1;
        }
    }
    base[1][0] = base[0][0] = 1;
    while(T) {
        if(T & 1) ans = ans * base;
        base = base * base;
        T >>= 1;
    }
    return (ans[1][1] + ans[1][0] -1 + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    exc['B'] = 1, exc['J'] = 2, exc['M'] = 4, exc['P'] = 8;
    nn = n + n;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        string s; cin >> s;
        int cnt = 0;
        for(auto c : s) cnt += exc[c];
        G[u].push_back({v, cnt});
    } 
    int T ;cin >> T;
    int cnt = 0;
    rep(i, 0, 15) {
        int t = __builtin_popcount(i), tmp = work(i, T);
        cnt = (cnt + (t % 2 ? -1 : 1) * tmp % mod + mod) % mod;     
    }
    cout << cnt << '\n';
    return 0;
}