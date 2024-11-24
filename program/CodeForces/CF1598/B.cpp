//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<VI> A(n +1, VI(6));
    int m = 5;
    rep(i, 1,n) rep(j ,1, m) cin >> A[i][j];
    if(n % 2) return cout << "NO\n", void();
    auto check  = [&](int x, int y)  {
        vector<int> use(n + 1);
        int c1, c2; c1 = c2 = 0;
        rep(i, 1, n) if(A[i][x]) {
            c1++;
            use[i] = 1;
        }
        rep(i, 1, n) if(A[i][y]) {
            c2++;
            use[i] = 1;
        }        
        if(accumulate(use.begin(), use.end(), 0) == n && c1 * 2 >= n && c2 * 2 >= n) return true;
        return false;
    };
    rep(i, 1, m) rep(j, i + 1, m) if(check(i, j)){
        cout << "YES\n";
        return void();
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}