#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
template<int siz = 2>
using AI = array<int, siz>;

void solve() {
    int n; cin >> n;
    int on = n;
    vector<int> tmp(n + 3);
    vector<AI<2>> rg(1);
    rep(i, 1, n) cin >> tmp[i];
    vector<int> A(1), cnt(1);
    for(int i = 2, l = 1; i <= n + 1; i++) {
        if(tmp[i] != tmp[i - 1]) cnt.emplace_back(i - l), rg.push_back({l, i - 1}), l = i, A.emplace_back(tmp[i - 1]);
    }
    n = (int) A.size() - 1;
    rep(i, 0, 2) A.emplace_back(0);
    vector<int> S(n + 4);
    set<int> s({0, n + 1});
    rep(i, 1, n + 1) S[i] = S[i - 1] + 1ll * A[i] * cnt[i];
    vector<int> op(n + 1); iota(op.begin(), op.end(), 0);
    sort(op.begin() + 1, op.end(), [&](const int &x, const int &y) {
        return A[x] > A[y];
    });
    vector<AI<2>> F(n + 2);
    auto update = [&](AI<2> &x, const AI<2> &y) {
        x[0] = min(x[0], y[0]); x[1] = max(x[1], y[1]);
    };
    F[n + 1] = {n + 1, n + 1};
    rep(c, 1, n) {
        int i = op[c];
        int l = *prev(s.lower_bound(i));
        int r = *s.lower_bound(i);
        int t = S[r - 1] - S[l];
        F[i] = {l, r - 1};
        if(t > A[l]) update(F[i], F[l]);
        if(t > A[r]) update(F[i], F[r]);
        s.insert(i);
    }
    tmp[0] = tmp[on + 1] = INT_MAX;
    vector<int> ans(on + 1);
    rep(i, 1, n) {
        rep(j, rg[i][0], rg[i][1]) {
            if(((tmp[rg[i][0] - 1] < A[i] && j == rg[i][0]) || (tmp[rg[i][1] + 1] < A[i] && j == rg[i][1]))) ans[j] = S[F[i][1]] - S[F[i][0]];
            else ans[j] = A[i];
            
        }
    }
    rep(i, 1, on) cout << ans[i] << " \n"[i == on];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}