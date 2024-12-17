#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<LL>;

constexpr int N = 100 + 5;

int mod;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k >> mod;
    vector<VI> F(n + 1, VI((n + 1) * n / 2 * k + 5));
    int sum = 0;
    F[0][0] = 1;
    rep(i, 1, n) {
        sum += i * (k);
        F[i] = F[i - 1];
        rep(j, i, sum) (F[i][j] += F[i][j - i]) %= mod;
        int del = (k + 1) * i;
        per(j, sum, del) F[i][j] = (F[i][j] - F[i][j - del] + mod) % mod;
    } 
    rep(i, 1, n) {
        LL ans = 0;
        rep(j, 0, sum) (ans += F[i - 1][j] * F[n - i][j] % mod) %= mod;
        ans *= (k + 1) % mod;
        ans = (ans - 1 + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}
/*
暴力枚举 k 计算 -> TLE，加入一个数 i，对平均数的贡献是 i - ave，但是这样做和直接做没有任何本质区别？
转移可以使用前缀和优化，但是在 0 的时候会出问题，需要单独处理。
考虑能否通过预处理的方式然后快速的查询，但是将两种方法揉和一下就可以了。
其实我们并不需要做很多次背包，本质上做的背包都是一样的。
*/
