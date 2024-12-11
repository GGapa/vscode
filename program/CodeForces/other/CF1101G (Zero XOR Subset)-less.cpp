#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct Line {
    vector<int> a;
    int n;
    Line(int _n) : n(_n), a(_n + 1) {}
    bool insert(int x) {
        per(i, n, 0) {
            if(!(x >> i & 1)) continue;
            if(!a[i]) 
                return a[i] = x, true;
            x ^= a[i];
        }
        return false;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), S(n + 1) ;
    int ans = 0;
    Line li(30);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] ^ A[i];
    if(S[n] == 0) return cout << -1 << '\n', 0;
    sort(S.begin() + 1, S.end(), greater<>());
    rep(i, 1, n) ans += li.insert(S[i]);
    cout << ans << '\n';
    return 0;
}
/*
题意可以转化为给你若干个区间，让你求得一种划分方案要求不能够组成任意一个区间

线性基没有异或和为 0 的子集。
*/