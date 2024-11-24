//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    ll sum  = 0;
    vector<int> A(n + 2), cnt(n + 1);
    rep(i ,1, n) cin >> A[i], sum += A[i];
    bool tag = 1;
    int mx = 0;
    while(tag) {
        tag = 0; mx = 0;
        fill(cnt.begin(), cnt.end(), 0ll);
        rep(i, 1, n) {
            cnt[A[i]]++;
            if(cnt[A[i]] >= 2) mx = max(mx, A[i]);
            A[i] = mx;
            sum += A[i];
        }
        fill(cnt.begin(), cnt.end(), 0ll);
        rep(i ,1, n) cnt[A[i]]++;
        rep(i ,1, n) if(cnt[i] == 1) tag = 1;
    }
    fill(cnt.begin(), cnt.end(), 0ll);
    rep(i ,1, n) cnt[A[i]]++;
    rep(i, 1, n) {
        if(A[i]) {
            if(cnt[A[i]] == 1) sum += A[i];
            else if(cnt[A[i]]) sum += (n - i) * A[i];
        }
    }
    cout << sum << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve(); 
    return 0;
}