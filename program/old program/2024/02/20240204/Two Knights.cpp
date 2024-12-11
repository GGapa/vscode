//Two Knights
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) {
        ll a = 1ll * (i * i) * (i * i - 1) / 2;
        ll b = 1ll * (4 * (i - 2) * (i - 1));
        cout << a - b << '\n';
    }
    return 0;
}