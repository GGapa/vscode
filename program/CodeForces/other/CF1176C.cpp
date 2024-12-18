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
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    auto tmp = A;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    rep(i, 1, n) A[i] = lower_bound(tmp.begin() + 1, tmp.end(), A[i]) - tmp.begin();
    vector<int> cnt(10);
    cnt[0] = n + 1;
    rep(i, 1, n) {
        if(cnt[A[i] - 1]) {
            cnt[A[i] - 1]--;
            cnt[A[i]]++;
        }
    }
    cout << n - 6 * cnt[6] << '\n';
    return 0;
}