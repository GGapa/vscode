#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end(), [&](const string &x, const string &y) {
        return x.size() > y.size();
    });

    LL ans = 0;
    gp_hash_table<string, int> mp;
    set<string> s;
     rep(i, 1, n) {
        s.clear();
        for(int len = 1; len <= A[i].size(); len++) for(int l = 0; l + len - 1 < A[i].size(); l++) {
            s.insert(A[i].substr(l, len));
        }
        for(auto c : s)  mp[c]++;
    }
    rep(i, 1, n) ans += (mp[A[i]] - 1);
    cout << ans << '\n';
    return 0;
}