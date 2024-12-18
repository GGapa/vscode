#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n + 1) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(++x; x <= n; x += lowbit(x)) (T[x] = max(T[x], v));
    }
    int ask(int x) {
        int res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(++x; x > 0; x -= lowbit(x)) (res = max(res, T[x]));
        return res;
    }
    void clear() {fill(T.begin(), T.end(), 0); }
};


void solve() {
    int n; cin >> n;
    BIT tr(n);
    vector<int> A(n + 1), mx(n + 1);  
    rep(i, 1, n) cin >> A[i], mx[A[i]] = i;
    rep(i, 1, n) mx[i] = max(mx[i], mx[i - 1]);
    vector<int> id(n);
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return A[x] > A[y];
    });
    vector<int> ans(n + 1);
    for(auto i : id) {
        ans[i] = A[i];
        ans[i] = max(ans[i], tr.ask(max(mx[A[i] - 1], i)));
        tr.add(i, ans[i]);
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}