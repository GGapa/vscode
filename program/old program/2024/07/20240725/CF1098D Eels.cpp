#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

multiset<int> st[35];
ll sum[35];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int o = 1, x; o <= n; o++) {
        char op; cin >> op;
        cin >> x; 
        int i = 0;
        for(; (1 << i + 1) <= x; i++) ;
        auto &s = st[i];
        if(op == '+') s.insert(x), sum[i] += x;
        else s.erase(s.find(x)), sum[i] -= x;
        ll ans = 0;
        // cout << "i: " << i << '\n';
        for(ll j = 0, ss = 0; j <= 30; j++ ) if(!st[j].empty()) {
            ans += st[j].size() - 1;
            int t = *st[j].begin();    
            if(ss * 2 >= t) ans++; 
            ss += sum[j];
            // cout << ss << '\n';
        }   
        cout << ans << '\n';
    }
    return 0;
}