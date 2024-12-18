#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; LL w;  cin >> n >> w;
    vector<int> p(n + 1), dep(n + 1), rec(n + 1);
    vector<int> b1(n + 1), b2(n + 1);
    rep(i, 2, n) cin >> p[i], dep[i] = dep[p[i]] + 1;
    for(int i = 1, x, y; i <= n; i++) {
        x = i, y = x % n + 1;
        while(x != y) {
            if(dep[x] < dep[y]) swap(x, y) ;
            (b1[x] ? b2[x] : b1[x]) = i, rec[i]++, x = p[x];
        }
    }
    int cnt = n; LL sum = 0; 
    for(LL i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        if(--rec[b1[x]] == 0) cnt--;
        if(--rec[b2[x]] == 0) cnt--;
        sum += y;
        cout << sum * 2 + 1ll * cnt * (w - sum) << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}