#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = (1 << 19) + 5 ;

int lg[N], pw[N], A[N];

struct Node {
    int l, r, s, mx ;   
    const Node operator+(const Node &x) const {
        return {max(l, s + x.l), max(x.r, x.s + r), s + x.s, max({r + x.l, mx, x.mx})} ;
    };
}tr[N];


void init(int n) {
    pw[0] = 1;
    rep(i, 1, n + 1) pw[i] = pw[i - 1] * 2 ;
    lg[1] = 0;
    rep(i, 2, pw[n + 1]) lg[i] = lg[i / 2] + 1;
}


int ls(int x) {return x << 1; } 
int rs(int x) {return (x << 1) | 1; }
int lowbit(int x) {return x & -x; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; init(n) ;
    for(int i = pw[n], x; i < pw[n + 1]; i++) {
        cin >> x;
        tr[i] = {max(x, 0), max(x, 0), x, max(x, 0)} ;
    }
    per(i, pw[n] - 1, 1) tr[i] = tr[ls(i)] + tr[rs(i)] ;
    int tp = (1 << n) - 1;
    vector<int> ans(tp + 1);

    ans[0] = tr[1].mx;
    rep(s, 1, tp) {
        int t = lg[lowbit(s)];
        for(int i = pw[t + 1] - 1; i >= 1; i--) {
            if((s >> lg[i]) & 1) tr[i] = tr[rs(i)] + tr[ls(i)];
            else tr[i] = tr[ls(i)] + tr[rs(i)];
        }
        ans[s] = tr[1].mx;
    }
    int q; cin >> q;
    int nw = 0;
    // rep(s, 1, tp) cout << ans[s] << " \n"[s == tp];
    while(q--) {
        int x; cin >> x;
        nw ^= (1 << n - x - 1);
        // cout << bitset<10>(nw) << '\n';
        cout << ans[nw] << '\n';
    }
    return 0;
}
/*
8 18 13 13 18 8 12
*/