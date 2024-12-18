// X-Plosives

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n, m; cin >> n; ) {
        vector<int> F(1e5 + 1);
        iota(F.begin(), F.end(), 0);
        function<int(int)>find = [&](int x) {
            return (F[x] == x ? x : F[x] = find(F[x]));
        };
        int ans = 0;
        do {
            cin >> m;
            n = find(n), m = find(m);
            if(n == m) ans++;
            else F[n] = m;
        }while(cin >> n && n != -1);
        cout << ans << '\n';
    }
    return 0;
}