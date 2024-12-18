//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size();
    if(is_sorted(s.begin(), s.end())) return cout << "YES\n", void();
    s = " " + s;
    // 分两种情况，第一种情况是删除 0 前面的 1 且后面不能再出现 0，条件是前面的 1 不能够连续。
    int lt = n + 1;
    rep(i, 2, n) if(s[i] == s[i - 1] && s[i] == '1') {
        lt = i + 1;
        break;
    }
    bool tag = true;
    rep(i, lt, n) if(s[i] == s[i - 1] && s[i] == '0') {
        tag = false;
        break;
    }
    if(tag) return cout << "YES\n", void();
    // 第二种情况，删除 1 后面所有的 0，终止条件还是有两个连续的 0，

    // tag = true;
    // rep(i, 2, n) if(s[i] == s[i - 1] && s[i] == '0') {
    //     tag = false;
    //     break;
    // }
    // if(tag) return cout << "YES\n", void();
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}