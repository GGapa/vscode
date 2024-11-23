#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long  
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7, N = 1e6 + 5;

int n, p; 
bool tag = false;
LL qpow(LL x, LL y, bool tp){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) {
            (ret = ret * x);
            if(ret >= mod) tag |= tp, ret %= mod;
        }
        (x = x * x);
        if(x >= mod) tag |= tp, x %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2, 0);}
    map<int, int> cnt;


void solve() {
    cin >> n >> p;
    cnt.clear();
    for(int i = 1, x; i <= n; i++)
        cin >> x, cnt[x]++;
    if(p == 1) return cout << (n & 1) << '\n', void();
    vector<pair<int, int>> A;
    for(auto p : cnt) A.emplace_back(p);

    LL ans = 0, ans1 = 0; bool tg = 1;

    int m = (int)A.size() - 1;
    per(i, m, 0) if(A[i].second & 1){
        int lt = A[i].first; LL pw = 1;
        if(tg) (ans += qpow(p, A[i].first, 0)) %= mod;
        else (ans1 += qpow(p, A[i].first, 0)) %= mod;
        tg ^= 1;
        tag = false;
        per(j, i - 1, 0) {
            pw = pw * qpow(p, lt - A[j].first, 1) % mod;
            if(pw >= n) tag = 1;
            if(tag) {
                if(tg) (ans += qpow(p, A[j].first, 0) * A[j].second % mod) %= mod;
                else (ans1 += qpow(p, A[j].first, 0) * A[j].second % mod) %= mod;
                A[j].second = 0;
            } 
            else {
                LL op = min(1ll * A[j].second, pw);
                if(tg) (ans += qpow(p, A[j].first, 0) * op % mod) %= mod;
                else (ans1 += qpow(p, A[j].first, 0) * op % mod) %= mod;
                pw -= op; A[j].second -= op;
            }
            lt = A[j].first;
            if(pw == 0 && tag == false) break;
        }
    }
    // cout << (ans1 - ans + mod) % mod << '\n';
    if(tg) cout << (ans1 - ans + mod) % mod << '\n';
    else cout << (ans - ans1 + mod) % mod << '\n';
}

signed main() {
    // freopen("data.in", "r", stdin);
    // freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
