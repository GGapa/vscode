#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; LL k; cin >> n >> k;
    vector<LL> A(n + 1), S(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    sort(A.begin() + 1, A.end(), greater<>());
    auto check = [&](int x) {
        // vector<LL> cnt(x + 1);
        // for(int i = 1, j = 1; i <= n; i++) {
        //     if(j == 1) {
        //         cnt[j] = A[i]; j++;
        //         continue;
        //     }
        //     LL t = A[i];
        //     while(j <= x && t) {
        //         LL ad = min(cnt[j - 1] - cnt[j], t);
        //         t -= ad; cnt[j] += ad;
        //         if(cnt[j] == cnt[j - 1]) j++;
        //         if(j == x + 1){
        //             fill(cnt.begin(), cnt.end(), 0);
        //             cnt[1] = t, j = 1 + (t != 0); 
        //             t = 0;
        //             break;
        //         }
        //         if(t == 0) continue;
        //     }
        // }
        // LL sum = 0;
        // rep(i, 2, x) sum += cnt[1] - cnt[i];
        // return sum <= k;
        // return cnt[1] - 
        LL now = 0, sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += A[i];
            if(sum >= now * x) now = sum - now * x, sum = now;
        }
        return now * x - sum <= k;
    };
    LL l = 0, r = n, ans = 0; 
    while(l <= r) {
        LL mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}