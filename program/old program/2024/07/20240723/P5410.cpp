#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e7 + 6;

int z[N], p[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> b >> a;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    z[1] = n;
    for(int i = 2, l = 0, r = 0; i <= n; i++) {
        int &j = z[i] = i > r ? 0 : min(r - i + 1, z[i - l + 1]) ;
        while(a[1 + j] == a[i + j] && j < n) j++;
        if(i + j - 1 > r) r = i + j - 1, l = i;
    }
    for(int i = 1, l = 0, r = 0; i <= m; i++) {
        int &j = p[i] = i > r ? 0 : min(r - i + 1, z[i - l + 1]) ;
        while(j < n && a[1 + j] == b[i + j]) j++;
        if(i + j - 1 > r) r = i + j - 1, l = i;
    }
    ll ans = 0;
    rep(i ,1, n) ans ^= 1ll * i * (z[i] + 1);
    cout << ans << '\n';
    ans = 0;
    rep(i ,1, m) ans ^= 1ll * i * (p[i] + 1);
    cout << ans << '\n';
    return 0;
}