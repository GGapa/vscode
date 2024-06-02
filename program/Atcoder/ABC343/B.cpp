// B
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n) rep(j, 1, n) {
        int x; cin >> x;
        if(x == 1) cout << j << " ";
        if(j == n) cout << '\n';
    }
    return 0;
}