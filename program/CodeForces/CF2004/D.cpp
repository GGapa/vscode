#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

string clo = "BGRY";

void solve() {
    int n, q; cin >> n >> q;
    map<string, vector<int>> pre, suf;    // 从左往右第一次不出现的位置，从右往左第一次不出现的位置。
    vector<string> A(n + 1);
    rep(i, 1, n) {
        auto &s = A[i];
        cin >> s;
        if(s[1] > s[0]) swap(s[1], s[0]) ;
    }
    auto init = [&](string s) {
        string ban;
        rep(i, 0, 3) if(clo[i] != s[0] && clo[i] != s[1]) ban += clo[i];
        if(ban[1] > ban[0]) swap(ban[1], ban[0]) ;
        if(s[1] > s[0]) swap(s[1], s[0]) ;
        auto &P = pre[s];
        P.resize(n + 2);
        rep(i, 1, n) {
            P[i] = P[i - 1];
            if(A[i] != s && A[i] != ban) P[i] = i;
        }
        auto &S = suf[s];
        S.resize(n + 2);
        S[n + 1] = n + 1;
        per(i, n, 1) {
            S[i] = S[i + 1];
            if(A[i] != s && A[i] != ban) S[i] = i;
        }
    };
    rep(i, 0, 3) rep(j, i + 1, 3) {
        string tmp = ""; tmp += clo[i]; tmp += clo[j];
        init(tmp);
    }
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(A[x] == A[y]) {
            cout << y - x << '\n';
            continue;
        }
        int ans = INT_MAX;
        string s = A[y];
        if(pre[s][y] > 0) ans = min(abs(y - pre[s][y]) + abs(x - pre[s][y]), ans) ;
        s = A[x];
        if(suf[s][x] <= n)ans = min(abs(y - suf[s][x]) + abs(x - suf[s][x]), ans) ;
        if(ans >= INT_MAX) ans = -1;
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
2 1
BG RY
1 2
*/