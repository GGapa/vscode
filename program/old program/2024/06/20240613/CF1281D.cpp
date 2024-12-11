//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>; 
#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<int> l(n + 1), r(n + 1);
    rep(i, 1, n) cin >> l[i];
    rep(i, 1, n) cin >> r[i];
    multiset<int> s;
    int cnt = 0, cost = 0, ans = LLONG_MAX;
    rep(i, 1, n) {
        int t = r[i] - l[i] + 1;
        s.insert(t);
        cnt += t;
        while(!s.empty() && cnt - *s.begin() >= m) {
            ans = min(ans, l[i] + min(t - 1, t - (cnt - m) - 1) + ((int)s.size()) * 2);
            cnt -= *s.begin(), s.erase(s.begin());
        }
        if(cnt >= m) ans = min(ans, l[i] + min(t - 1, t - (cnt - m) - 1) + ((int)s.size()) * 2);
    }   
    if(ans == LLONG_MAX) return cout << -1 << '\n', void();
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
考虑到 r < l(i + 1) - 1
而每一次按压会造成 2 点的额外贡献
在什么情况下这个区间是可以通过舍弃之间的区间换来的呢？
对于一个区间的右端点 r，我们至少都会有 r - r(i - 1)的贡献

考虑枚举右端点，接着拿着一个 set 去统计答案
我怎么这么聪明？
1
3 5
1   102 105
4 103 110
*/