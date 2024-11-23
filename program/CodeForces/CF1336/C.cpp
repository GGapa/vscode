#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int mod = 998244353, N = 3000 + 5;
int F[N][N], tag[N];

void dfs(int i, int l, int r) {

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s, t = " " + t;

    // tag[0] = 1;
    // rep(i, 1, m) tag[i] = tag[i - 1] && (t[i] == t[m - i + 1]);  // 预处理两个能不能交换

    // LL ans = 0;
    // F[0][0][0] = 1, F[1][0][m + 1] = 1;
    // rep(i, 0, n - 1) {
    //     rep(j, 0, m - 1) {
    //         if(s[i + 1] == t[j + 1]) (F[0][i + 1][j + 1] += F[0][i][j]) %= mod;
    //         (F[0][i + 1][j] += F[0][i][j]) %= mod;
    //     }   // 正面情况
    //     per(j, m + 1, 2) {
    //         if(s[i + 1] == t[j - 1]) (F[1][i + 1][j - 1] += F[1][i][j]) %= mod;
    //         (F[1][i + 1][j] += F[1][i][j]) %= mod;
    //     }   // 反面情况
    //     rep(j, 1, m) if(tag[j]) {
    //         (F[0][i + 1][j] += F[1][i][m - j + 1]) %= mod;
    //         (F[1][i + 1][j] += F[0][i][m - j + 1]) %= mod;
    //         if(s[i] == t[j + 1]) (F[0][i + 1][j + 1] += F[1][i][m - j + 1]) %= mod;
    //         if(s[i] == t[j - 1]) (F[1][i + 1][j - 1] += F[0][i][m - j + 1]) %= mod;
    //     }
    //     rep(j, 0, m + 1) cerr << F[0][i][j] << " \n"[j == m + 1];
    //     rep(j, 0, m + 1) cerr << F[1][i][j] << " \n"[j == m + 1];
    //     cout << ans << '\n';
    //     cout << '\n';
    // }
    // rep(i, 0, n) (ans += (1ll * F[0][i][m] * 1ll * (n - i + 1) + F[1][i][1] * (i) % mod) % mod) %= mod;
    // cout << ans << '\n';

    rep(i, 1, m) if(t[i] == s[1]) F[i][i] = 1;    
    rep(i, m + 1, n) F[i][i] = 1;
    rep(j, 1, n) per(i, j - 1, 1) {
        int l = (j - i + 1);
        if(j > m || s[l] == t[j]) (F[i][j] += F[i][j - 1]) %= mod;
        if(i > m || s[l] == t[i]) (F[i][j] += F[i + 1][j]) %= mod;
    }
    LL ans = 0;
    rep(j, m, n) (ans += F[1][j]) %= mod;
    cout << 1ll * ans * 2 % mod << '\n';
    return 0;
    
}
/*

定义 F[i][j] 代表合成到 t(i, j) 的方案数是多少，每次可以添加，还可以顶掉
初始状态为 F[i][i] = 1, 前提是 s[i] = t[1] 但是这样似乎并不能正确的解决问题。

----------

或许可以考虑区间 DP?

以下全部假了，确实该考虑区间 DP
F(i, j) 代表 s 在 i、t 在 j 的方案数是多少，但是这样并没有考虑到一个问题，那就是从后往前构建方案。
考虑定义 F(i, j, 2) 代表代表 s 在 i、t 在 j，从前0 还是后1，考虑如何转移/

这是 0 的情况
F[i + 1][j + 1] += F[i][j] s[i + 1] == t[j + 1]
F[i + 1][j] += F[i][j]

这是 1 的情况
F[i + 1][j - 1] += F[i][j] s[i + 1] == t[j - 1]
F[i + 1][j] += F[i][j]
这种 DP 会不会将两种情况算重，似乎并不会！值得一提的是还会算漏


现在考虑如何排查 0 和 1 互相转换的情况，
现在还要考虑不同层级之间的转移

首先先处理出辅助数组 tag[i] 代表 t[1..i] == t[n - i + 1...n]
此时就可以出现不同层级之间的转换。0 -> 1 或 1 -> 0

F[0][i + 1][n - j + 1] += F[1][i][j] + (s[i + 1] == t[n - j + 1] && tg[j] == 1)

F[1][i + 1][n - j] += F[1][i][j] + (s[i + 1] == t[n - j] && tg[n - j + 1] == 1)     

这两个转移有点问题，此处未更正



似乎这样子就全面了？似乎并不需要考虑更多的情况，比如说不同层级之间不增加 j  的转移。WARNING 这一点应该是非常有必要的。



----------


现在考虑初始条件 F[0][0][0] = 1, F[1][0][n + 1] = 1;
*/