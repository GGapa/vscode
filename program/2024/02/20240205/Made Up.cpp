//AtCoder - abc202_c
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

const int N  = 1e5 + 5;

int a[N], b[N], c[N], d[N], n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) d[b[c[i]]]++;
    ll ans = 0;
    rep(i, 1, n) ans += d[a[i]];
    cout << ans << '\n';
    return 0;
}