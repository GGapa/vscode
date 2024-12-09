#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 6;

int c1[N], c2[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    for(int i = 1; i <= n; i += 2) c1[A[i]] += 1;
    for(int i = 2; i <= n; i += 2) c2[A[i]] += 1;

    int mx1 = 0, mx2 = 0, ans = INT_MAX;
    rep(i, 1, N - 1) {
        if(c1[i] > c1[mx1]) mx2 = mx1, mx1 = i;
        else if(c1[i] > c1[mx2]) mx2 = i;
    }

    int m1 = 0, m2 = 0;
    rep(i, 1, N - 1) {
        if(c2[i] > c2[m1]) m2 = m1, m1 = i;
        else if(c2[i] > c2[m2]) m2 = i;
    }
    if(mx1 != m1) ans = min(ans, n - c1[mx1] - c2[m1]);
    else ans = min({ans, n - c1[mx1] - c2[m2], n - c1[mx2] - c2[m1]});

    cout << ans << '\n';
    return 0;
}