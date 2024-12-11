#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 2);
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, x; i <= n; i++) 
        cin >> x, A[i] = -A[i] + x;
    ll ans = 0;
    rep(i, 1, n) {
        auto &a = A[i], &a1 = A[i + 1];
        if(a >= 0 && a1 >= 0) ans += max(0ll, (a - a1));
        else if(a <= 0 && a1 <= 0) ans += max(0ll, (a1 - a));
        else if(a >= 0 && a1 <= 0) ans += a;
        else ans += -a;
    }
    cout << ans << '\n';
    return 0;
}
/*
2 -1 2 3
*/