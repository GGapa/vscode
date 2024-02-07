#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, N = 1e6 + 5;
#define int long long

ll a[N];
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a[1] = 0;
    rep(i, 2, n) {
        a[i] = a[i - 1] * (i) + (i % 2 == 0)  - (i % 2 == 1);
        a[i] %= mod;
    }
    cout << a[n] << '\n';
    return 0;
}