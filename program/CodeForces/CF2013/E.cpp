#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    auto getp = [&](int x) {
        vector<int> ret;
        for(int i = 2; x > 1; i++) if(x % i == 0) {
            ret.emplace_back(i);
            while(x % i == 0) x /= i;
        }
        return ret;
    };
    vector<int> F(n + 1);
    auto bs = getp(A[1]);
    rep(i, 1, n) {
        auto tmp = getp(A[i]);
        for(auto t : tmp) {
            auto it = find(bs.begin(), bs.end(), t);
            if(it == bs.end()) continue;
            F[i] |= (1 << (it - bs.begin()));
        }
    }
    int m = bs.size(), tp = (1 << m) - 1;
    vector<int> nd(tp + 1);
    rep(s, 0, tp) rep(i, 1, n) if((F[i] & s) == 0) nd[s]++;
    
    LL nw = A[1], ans = A[1], cnt = 1;
    for(int tag = 1; tag; ) {
        tag = 0;
        auto tmp = getp(nw);
        int s = 0;
        for(auto t : tmp) {
            auto it = find(bs.begin(), bs.end(), t);
            if(it == bs.end()) continue;
            s |= (1 << (it - bs.begin()));
        }
        int nxt = A[n] + 1;
        for(int i = s; i; i = (i - 1) & s) if(nd[i]) {
            int tp = s ^ i;
            int ttt = 1;
            rep(j, 0, m - 1) if(tp >> j & 1) ttt *= bs[j];
            tag = 1; 
            nxt = min(nxt, ttt);
        }
        cnt += tag; 
        if(tag) {
            nw = nxt;
            ans += nw;
        }
    }
    cout << ans + (n - cnt) * nw << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
一个数字的质因子个数一定是非常少的，只有七个
*/