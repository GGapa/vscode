#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    int tp = (1 << n) - 1;

    vector<int> pre(tp + 1), suf(tp + 1), si(tp + 1), A(tp + 1);
    string S; cin >> S;
    rep(i, 0, tp) A[i] = pre[i] = suf[i] = S[i] - '0', si[i] = __builtin_popcount(i);

    rep(i, 0, n - 1) rep(s, 0, tp) {
        if(s >> i & 1) pre[s] += pre[s ^ (1 << i)];
        else suf[s] += suf[s ^ (1 << i)];
    }

    for(int a, b, c, ans; q--; ) {
        a = b = c = ans = 0; cin >> S;
        for(int i = 0; i < n; i++) 
            a = (a << 1) + (S[i] == '0'), b = (b << 1) + (S[i] == '1'), c = (c << 1) + (S[i] == '?');
        if(si[a] <= si[b] && si[a] <= si[c]) {
            ans = suf[b];
            for(int s = a; s; s = (s - 1) & a) 
                ans -= suf[b ^ s] * ((si[s] & 1) == 1 ? 1 : -1);
        }
        else if(si[b] <= si[c]) {
            a ^= tp;
            ans = pre[a];
            for(int s = b; s; s = (s - 1) & b) 
                ans -= pre[a ^ s] * ((si[s] & 1) == 1 ? 1 : -1);
        } 
        else {
            ans = A[b];
            for(int s = c; s; s = (s - 1) & c) ans += A[b ^ s]; 
        }
        cout << ans << '\n';
    }

    return 0;
}
