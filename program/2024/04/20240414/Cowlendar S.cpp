// Cowlendar S
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
    set<int> S, ls;
    for(int i = 1, x; i <= n; i++)  
        cin >> x, S.insert(x);
    vector<int> A(S.begin(), S.end());
    int top = A[0]/ 4;
    if(A.size() < 4) return cout << top * (top + 1) / 2 << '\n', 0;
    int m = A.size() - 1;
    rep(i, 0, 3) rep(j, i + 1, 3) {
        int d = A[j] - A[i];
        for(int k = 1; k * k <= d; k++) 
            if(d % k == 0) ls.insert(k), ls.insert(d / k);
    }
    auto check = [&](int x) {
        set<int> F;
        for(auto a : A) {
            F.insert(a % x);
            if(F.size() > 3) return false;
        }
        return true;
    };
    int ans = 0;
    for(auto l : ls) {
        if(check(l)) ans += l;
    }
    cout << ans << '\n';
    return 0;
}