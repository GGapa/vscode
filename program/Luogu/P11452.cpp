#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<LL, 2>;

struct DSU {
    vector<int> fa;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1); 
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    LL sum = accumulate(A.begin(), A.end(), 0ll), ans = 0;
    

    // else {
        vector<LL> S(n + 1);
        rep(i, 1, n) S[i] = S[i - 1] + A[i];
        int t = n / 2 - 1;
        // LL ans = 0;
        rep(i, 0, t) ans = max(ans, S[i] + S[n] - S[n - (t - i)]);
        cout << sum - ans << " " << ans << '\n';
    // }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}