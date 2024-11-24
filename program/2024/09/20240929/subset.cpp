#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int k, b, s;

namespace sub1 {
    void solve() {
        for(int x = 0; k * x + b <= s; x++) if(((k * x + b) & s) == (k * x + b)) return cout << x << '\n', void();
        return cout << -1 << '\n', void();
    }
} // namespace sub1


namespace funny {
    const int N = 4e4 + 5, BL = 15;
    int F[N];
    vector<int> cnt((1 << BL) + 5), mn = cnt;
    void solve() {
        fill(cnt.begin(), cnt.end(), -1); fill(mn.begin(), mn.end(), 0);
        int ans = 2e9;
        // cerr << bitset<BL> (s) << '\n';
        for(int y = s & ((1 << BL) - 1); y; y = (y - 1) & (s & ((1 << BL) - 1))) mn[y % k] = max(mn[y % k], y);     // 这里脑子笨了，完全可以先处理前 15 位，然后再处理后 15 位。
        for(int x = s >> BL, tag = 1; tag; x = (x - 1) & (s >> BL)) {
            // if(x == 0) cerr << (s & ((1 << BL) - 1))<< '\n';
            if(x == 0) tag = false;
            if((x << BL) + (s & ((1 << BL) - 1)) >= b){
                int t = ((b - (x << BL)) % k + k) % k;
                if(t >= (1 << BL)) continue;            // 哎呀，我真的是脑子抽了，明明这里直接 continue 就好了，但是我要硬加 unorderedmap 我真的不知道我当时在想什么。。。。。。
                if(b - (x << BL) > mn[t]) continue;
                cnt[t] = x;
            }
        }
        for(int y = s & ((1 << BL) - 1), tag = 1; tag; y = (y - 1) & (s & ((1 << BL) - 1))) {
            // if(y == 1) cerr << cnt[y % k] << '\n';
            // cerr << y << '\n';
            if(y == 0) tag = false;
            int x = cnt[y % k];
            int tt = (x << BL) + y - b;
            if(tt < 0) continue;
            if(x == -1) continue;
            assert(tt % k == 0);
            ans = min(ans, tt / k);
            if(y == 0) break;
        }
        if(ans == 2e9) ans = -1;
        cout << ans << '\n';
    }
};  // 正解
/*
$(x << BL) + y \equiv b \pmod{k}$

$y \equiv b - (x << BL) \pmod k$
*/

void solve() {
    cin >> k >> b >> s;
    funny::solve();
}

signed main() {
    // freopen("subset.in", "r", stdin);
    // freopen("subset.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*

1
18 55 268961793

14942205

268959745

x = 8208
y = 


*/
