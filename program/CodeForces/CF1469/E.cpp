// E. A Bit Similar
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    int k = min((int)__lg(n) + 1, m);
    string s; cin >> s;
    s = " " + s + " ";
    vector<int> cnt(n + 1), bad((1 << k) + 1);
    int nw = 0, mx = (1 << k) - 1;
    rep(i, 1, n) cnt[i] = (s[i - 1] == '1' ? cnt[i - 1] + 1 : 0);   //统计连续的 1
    rep(i, 1, k) nw = (nw << 1) | (s[i] - '0');
    rep(i, 1, n - k + 1) {
        if(cnt[i] >= m - k) bad[(~nw) & mx] = 1;    //若此时有连续的 1 的数量已经超过了所填充的前缀。
        if(i != n + 1) nw = ((nw << 1) | (s[i + k] - '0')) & mx;
        // cout << bitset<10>((~nw) & mx) << '\n';
    }
    int ans = -1;
    // cout << mx << '\n';
    rep(i, 0, mx) if(!bad[i]) {ans = i; break;} 
    if(ans == -1) return cout << "NO\n", void();
    cout << "YES\n";
    rep(i, 1, m - k) cout << '0';
    per(i, k - 1, 0) cout << ((ans & (1 << i)) ? '1' : '0');
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
突破点一：若一个 01 串和原字符串完全不同，则就是原字符串取反后的结果。

突破点二：有 $(n - k + 1)$ 个限制串，则只需要枚举 $2^i > (n - k + 1)$ 个后缀，前缀任意填充，则一定能找到一个与限制串不同的串，也就是所谓的**抽屉原理**，由数据范围可得，直接枚举处理。

**注意**：由于字典序最小，前缀应当填 0，若前缀填 0 则已经能将一些限制穿的影响消除。

*/