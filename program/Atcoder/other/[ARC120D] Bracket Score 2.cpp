#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m = n * 2;
    vector<int> A(m + 1), sm(m + 1), id(m);
    rep(i, 1, m) cin >> A[i];
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return A[x] < A[y];
    });
    rep(i, 0, n - 1) sm[id[i]] = 1;
    int cnt = 0;
    string ans;
    int tp = 0;
    rep(i, 1, m) {
        cnt += (sm[i] ? 1 : -1);
        if(cnt > 0) ans += (sm[i] ? '(' : ')');
        else if(cnt < 0) ans += (sm[i] ? ')' : '(');
        else ans += ')';
        tp = (cnt > 0 ? 1 : 0);
    }
    cout << ans << '\n';
    return 0;
}