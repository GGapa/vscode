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
    int n, m, k; cin >> n >> m >> k;
    int tp = (1 << n) - 1;
    vector<VI> A(m + 1);
    vector<char> re(m + 1);
    rep(i, 1, m) {
        int l; cin >> l;
        rep(j, 1, l) {
            int x; cin >> x;
            A[i].emplace_back(x);
        }
        cin >> re[i];
    }
    int ans = 0;
    rep(c, 0, tp) {
        bool tag = true;
        rep(i, 1, m) {
            int cnt = 0;
            char ch = 'x';
            for(auto a : A[i]) {
                if((c >> (a - 1)) & 1)  
                    cnt++;
            }
            if(cnt >= k) ch = 'o';
            if(ch != re[i]) {
                tag = false;
                break;
            }
        }
        if(tag) ans += 1;
    }
    cout << ans << '\n';
    return 0;
}