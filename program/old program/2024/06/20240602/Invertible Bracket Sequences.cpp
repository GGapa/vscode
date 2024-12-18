//君本凌云客，何故喜蓬蒿？
// D. Invertible Bracket Sequences Educational Codeforces Round 166 (Rated for Div. 2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size();
    map<int, int> cnt ;
    int num = 0, ans = 0;
    for(auto c : s) {
        num += (c == '(' ? 1 : -1);
        ans += cnt[num]++;
        while(cnt.begin()->first * 2 < num) cnt.erase(cnt.begin());
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    int T; cin >> T;
    while(T--) solve();
    return 0;   
}