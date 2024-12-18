#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a :  A) cin >> a;
    vector<int> ans;
    auto check = [&]() {
        for(auto a : A) if(a != 0) return true;
        return false;
    };
    while(ans.size() <= 40 && check()) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int t = A.size();
        LL mi = (A.back() - A.back() / 2);
        mi = max(mi, 1LL);
        ans.push_back(mi);
        for(auto &a : A) a = abs(a - mi);
    }
    if(ans.size() > 40) return cout << "-1\n", void();
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}