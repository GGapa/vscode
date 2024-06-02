// A
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b; cin >> a >> b;
    if(b != 0) cout << a;
    else if(a != 0) cout << b;
    else cout << 1 << '\n';
    return 0;
}