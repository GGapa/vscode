#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

vector<int> tmp;

LL mul(int l, int r) {
    if(l > r) return 0;
    l = tmp[l], r = tmp[r];
    return qpow(2, r - l);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 2);
    rep(i ,1, n) cin >> A[i];x
    tmp = A;
    tmp.push_back(1);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    rep(i, 1, n) A[i] = lower_bound(tmp.begin() + 1, tmp.end(), A[i]) - tmp.begin();
    vector<LL> F(n + 1);
    F[0] = 1;
    rep(i, 1, n) {
        if(A[i] >= A[i - 1]) {
            LL t = F[A[i - 1]];
            rep(j, 1, A[i - 1] - 1) 
                (F[j] *= mul(A[i - 1], A[i])) %= mod;
            rep(j, A[i - 1], A[i]) 
                F[j] = (2ll * t * ((mul(j, A[i]) - mul(j + 1, A[i]) + mod) % mod)) % mod;
        }
        else {
            (F[A[i]] *= 2) %= mod;
            rep(j, A[i] + 1, A[i - 1]) 
                (F[A[i]] += 2 * F[j]) %= mod, F[j] = 0;
        }
    }

    LL ans = 0;
    rep(i, 1, A[n]) (ans += F[i]) %= mod;
    cout << ans << '\n';
    return 0;
} 