#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q; 
    vector<int> A(n + 1), S(n + 1), xo(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i], xo[i] = (xo[i - 1] ^ A[i]);
    vector<int> nt(n + 1) ;
    unordered_map<int, int> mp[2];
    per(i, n, 0) {
        nt[i] = mp[(i % 2) ^ 1][xo[i]];
        if(!nt[i]) nt[i] = n + 1;
        mp[i % 2][xo[i]] = i;
    }

    auto work = [&](int l, int r) {
        int len = r - l + 1;
        if(xo[r] ^ xo[l - 1]) return -1;
        if(S[r] - S[l - 1] == 0) return 0;
        if(len % 2) return 1; 
        if(nt[l - 1] <= r) return 2 - (A[l] == 0 || A[r] == 0);
        return -1;
    };
    for(int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        cout << work(l, r) << '\n';
    }
    return 0;
}