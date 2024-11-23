#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<set<int>> S(n + 2);
    vector<int> A(n + 1), B(m + 1), C(n + 1);
    rep(i, 1, n) cin >> A[i], C[A[i]] = i;
    rep(i, 1, m) cin >> B[i], S[C[B[i]]].insert(i); 
	int cnt = 0;
	auto check = [&](int x) {
        if(x == 0 || x == n) return false;                 
        if(S[x].empty()) return S[x + 1].empty();       // 这个不行看下一个。
        return (S[x + 1].empty() || *S[x].begin() < *S[x + 1].begin());     // 如果满足条件
    };
    rep(i, 1, n) cnt += check(i);
    cout << (cnt == n - 1 ? "YA" : "TIDAK")  << '\n';
    for(int x, y; q--; ) {
        cin >> x >> y;
        cnt -= check(C[B[x]] - 1) + check(C[B[x]]);     // 删除，然后计算贡献
        S[C[B[x]]].erase(x);
        cnt += check(C[B[x]] - 1) + check(C[B[x]]);
        B[x] = y;
        cnt -= check(C[B[x]] - 1) + check(C[B[x]]);     // 添加，然后计算贡献
        S[C[B[x]]].insert(x);         
        cnt += check(C[B[x]] - 1) + check(C[B[x]]);
        cout << (cnt == n - 1 ? "YA" : "TIDAK")  << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
// 过过过！！！！！