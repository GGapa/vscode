//

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    ll sum = (1 + k) * k / 2;
    set<int> s;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(!s.count(x) && x <= k) {
            sum -= x;
            s.insert(x);
        }
    }
    cout << sum << '\n';
    return 0;
}