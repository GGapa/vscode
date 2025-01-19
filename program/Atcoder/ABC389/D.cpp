#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n; cin >> n;
    LL ans = 0;
    LL x = n;
    for(LL i = 0; i < n; i++) {
        while((1 + 2 * i) * (1 + 2 * i) + (2 * x + 1) * (2 * x + 1) > 4 * n * n) x--;
        if(i) ans += 2 * x + 1;
        ans += 2 * x + 1;
    } 
    cout << ans << '\n';
    return 0;
}