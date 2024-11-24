//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> L(m + 1), R(m + 1), C(m + 1);
    rep(i ,1, m) cin >> L[i] >> R[i] >> C[i];
    vector<int> id(m + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
        return C[x] < C[y];
    });
    vector<int> fa(n + 2);
    iota(fa.begin(), fa.end(), 0);  
    function<int(int)> find = [&](int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    };
    ll ans = 0;
    rep(c, 1, m) {
        int i = id[c];
        ans += C[i];
        for(int j = find(L[i]); j < R[i]; j = find(j)) {
            int t1 = find(j + 1), t2 = find(j);
            if(t1 == t2) continue;
            fa[t2] = t1;
            ans += C[i];
        }       
    }
    if(find(1) != n) return cout << -1 << '\n', 0;
    cout << ans << '\n';
    return 0;
}