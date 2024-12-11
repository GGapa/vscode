//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<int> fa(n + m + 1), cnt(n + m + 1);
    function<int(int)> find = [&](int x) {
        if(x == fa[x]) return x;
        int rt = find(fa[x]);
        cnt[x] += cnt[fa[x]];
        return fa[x] = rt;
    };
    iota(fa.begin(), fa.end(), 0);
    bool tag = false;
    for(int i = 1, a, b, c; i <= k; i++) {
        cin >> a >> b >> c;
        b += n;
        int x = find(a), y = find(b);
        if(tag) continue;
        if(x != y) {
            fa[y] = x;
            cnt[y] = c + cnt[a] - cnt[b];
        }
        else if(cnt[b] - cnt[a] != c) tag = true;
    }
    if(tag) return cout << "No\n", void();
    cout << "Yes\n";
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    cin >> T;
    while(T--) solve();
    return 0;
}