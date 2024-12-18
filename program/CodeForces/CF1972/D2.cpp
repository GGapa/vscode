// D2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;


void solve() {
    int n, m; cin >> n >> m;
    // int cnt = 0;
    // rep(a, 1, n) rep(b, 1, m) if(b * __gcd(a, b) % (a + b) == 0) 
    //     cnt++, cout << a << " " << b << '\n';
    // cout << cnt << '\n';
    int cnt = 0;
    // rep(i, 1, m) {
    //     int tp = sqrt(i);
    //     rep(j, 1, tp) if(i % j == 0){
    //         int t = j - 1;
    //         ans += (t > 0 && t * i <= n );
    //         if(i / j == j) continue;
    //         t = i / j - 1;
    //         ans += (t > 1 && t * i <= n);
    //     }
    // }
    // rep(b, 1, m) for(int a = b; a <= n; a += b)  {
    //     if((__gcd(a, b)) % ((a + b) / b) == 0 ) {
    //         // cout << a << " " << b << '\n';
    //         cnt++;
    //     }
    // }
    for(int a = 1; a * a <= n; a++) for(int b = 1; b * b <= m; b++) if(__gcd(a, b) == 1) cnt += min(n / (a + b) / a, m / (a + b) / b);
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
(a + b) | gcd(a, b) * b;
g = gcd(a, b);
a = gq, b = gp;
(q + p) * k = gp; 
qk + pk = gp
q + p = gp / k
q / p + 1 = g / k
gcd(p, q) = 1 => p = 1;
q + 1 = g / k;

https://zhuanlan.zhihu.com/p/695554049
https://codeforces.com/contest/1972/submission/258920365
https://www.cnblogs.com/663B/p/18169162
*/  