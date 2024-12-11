
//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n + 1);
    vector<int> ps;
    x++;
    int ans = -1;
    auto work = [&]() {
        int ret = 0;
        vector<int> cnt(35);
        rep(i, 1, n) {
            auto a = A[i];
            for(auto t : ps) if((a >> t) & 1) cnt[t]++;
            bool tag = true;
            rep(j, 0, 30) if(cnt[j] % 2) {tag = false; break;}
            if(tag) {
                ret++;
                fill(cnt.begin(), cnt.end(), 0);
            }
        }
        bool tag = true;
        rep(j, 0, 30) if(cnt[j] % 2) {tag = false; break;}
        if(!tag) return -1;
        return ret;
    };
    rep(i, 1, n) cin >> A[i];
    per(i, 30, 0) {
        if((x >> i) & 1) {
            ps.push_back(i);
            ans = max(ans, work());
            ps.pop_back();
        }
        else ps.push_back(i);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T ;
    while(T--) solve();
    return 0;
}
/*
考虑一个数字
10
11
01
*/