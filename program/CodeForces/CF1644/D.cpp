#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;

}

const int N = 2e5 + 5;
int X[N], Y[N], A[N], B[N];

void solve() {
    int n, m, k, q; cin >> n >> m >> k >> q;   
    // vector<int> X(q + 1), Y(q + 1), A(n + 1), B(m + 1);
    fill(A, A + 1 + n, 0); fill(B, B + 1 + m, 0);
    rep(i, 1, q) cin >> X[i] >> Y[i];
    int cnt = 0;
    int c1, c2; c1 = c2 = 0;
    per(i, q, 1) {
        bool tag = 0;
        if(!A[X[i]] && c1 < n && c2 < m) tag = 1, A[X[i]] = 1, c1++;
        if(!B[Y[i]] && c1 < n && c2 < m) tag = 1, B[Y[i]] = 1, c2++;  
        cnt += tag;
    }
    cout << qpow(k, cnt) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}