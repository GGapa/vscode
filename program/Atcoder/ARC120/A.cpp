#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<LL> A(n + 1), mx(n + 1);
    rep(i, 1, n) cin >> A[i];

    LL sum = 0, add = 0;
    vector<LL> ans;
    rep(i, 1, n) sum += 1ll * (n - i + 1) * A[i], add += A[i];
    rep(i, 1, n) mx[i] = max(mx[i - 1], A[i]);

    per(i, n, 1) {
        ans.emplace_back(sum + i * mx[i]);
        sum -= add; add -= A[i];
    }

    for_each(ans.rbegin(), ans.rend(), [](auto x){cout << x << '\n'; });

    return 0;
}