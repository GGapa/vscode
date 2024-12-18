#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1) ;
    LL sum = 0;
    rep(i, 1, n) cin >> A[i], sum += A[i];
    vector<LL> p;
    for(LL i = 2; i * i <= sum; i++) {
        if(sum % i == 0) {
            while(sum % i == 0) sum /= i;
            p.emplace_back(i);
        }
    }
    if(sum != 1) p.emplace_back(sum);
    if(p.empty()) return cout << -1 << '\n', 0;
    sort(p.begin(), p.end());
    LL l = 0, r = p.size() - 1;
    auto check = [&](LL x) {
        LL ret = 0, nw = 0;
        rep(i, 1, n) {
            LL t = A[i] % x, t2 = t - x;
            if(abs(nw + t) < abs(nw + t2)) nw = nw + t;
            else nw = nw + t2;
            ret += abs(nw);
        }
        return ret; 
    };
    LL ans = LLONG_MAX;
    rep(i, l, r) ans = min(ans, check(p[i]));
    cout << ans << '\n';
    return 0;
}