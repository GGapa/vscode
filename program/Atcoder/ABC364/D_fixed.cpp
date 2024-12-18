#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    vector<LL> S(n + 1);
    rep(i ,1 ,n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    rep(i, 1, n) S[i] = S[i - 1] + A[i];
    for(int o = 1, b, k; o <= q; o++) {
        cin >>  b >> k;
        int l = 0, r = 2e8, ans = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            int t = upper_bound(A.begin() + 1, A.end(), b + mid) - lower_bound(A.begin() + 1, A.end(), b - mid);
            if(t >= k) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}