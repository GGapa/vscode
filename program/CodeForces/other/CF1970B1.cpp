//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    cout << "YES\n";
    rep(i, 1, n) cout << i << " " << i << '\n';
    rep(i, 1, n) cout << (i + A[i] / 2 <= n ? i + A[i] / 2 : i - A[i] / 2) << " \n"[i == n];
    return 0;
}