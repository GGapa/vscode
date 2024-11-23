#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, p, k; cin >> n >> p >> k;
    vector<int> A(n + 1);
    vector<LL> S(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    rep(i, 1, n) S[i] = S[i - 1] + A[i];

    int ans = 0;
    rep(i, 0, k) {
        if(S[i] > p) break;
        int sum = S[i], cnt = 0;
        for(int j = i + k; j <= n; j += k) {
            sum += A[j]; cnt++;
            if(sum > p) break;
            ans = max(ans, cnt * k + i);
        }
    }
    rep(i, 1, n) if(S[i] <= p) ans = max(ans, i);
    cout << ans << '\n';
}
/*
我是傻逼吗？我以为只能够使用一次优惠券，还有这是啥水样例啊，我真的受不了了
我题看错了都能够过样例，服了/
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}