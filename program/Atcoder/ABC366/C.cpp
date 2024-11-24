#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> cnt(1e6 + 5);
    int n; cin >> n;
    int ans = 0;
    for(int i = 1, op, x; i <= n; i++) {
        cin >> op;
        if(op == 3) {
            cout << ans << '\n';
            continue;
        }
        cin >> x;
        if(op == 1) {
            if(cnt[x] == 0) ans++;
            cnt[x]++;
        }
        else {
            if(cnt[x] == 1) ans--;
            cnt[x]--;
        }
    }
    return 0; 
}