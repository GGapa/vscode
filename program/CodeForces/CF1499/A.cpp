//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    auto work = [&](int &w, int k1, int k2) {
        w -= min(k1, k2) ; 
        w -= (max(k1, k2) - min(k1, k2)) / 2;
    };
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w, b; cin >> w >> b;    
    work(w, k1, k2);
    work(b, n - k1, n - k2);
    if(w > 0 || b > 0) return cout << "NO\n", void();
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}