#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), F(n + 1);
    rep(i, 1, n) cin >> A[i], F[A[i]] = i;
    rep(i, 1, n) {
        if(F[i] > i) F[i] = i + n - F[i];
        else F[i] = i - F[i];
    }
    BIT T(n * 3);
    vector<int> ans(n + 1);
    rep(i, 1, n) T.add(i + F[A[i]] + n, 1);
    per(i, n, 1) {
        ans[A[i]] += T.ask(i + F[A[i]]);
        T.add(i + F[A[i]], 1) ;
    }
    rep(i, 1, n) cout << F[i] - ans[i] << " \n"[i == n];

}
/*
如果能够被跳过则说明起点在 i 后面，而且终点还在 i 前面
i < j < i + F[i] && i < j + F[j] < i + F[i]
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}