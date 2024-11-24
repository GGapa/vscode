#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using BI = __int128;

void solve() {
    int n, k; cin >> n >> k; 
    ll x; cin >> x; x--;
    string s; cin >> s; s = " " + s;
    vector<int> ans(n + 1, 0), S(n + 2);
    per(i, n, 1) S[i] = S[i - 1] + (s[i] == '*');
    ll bas = 1;
    per(i, n, 1) {
        if(s[i] == 'a') break;
        ans[i] = 0; 
        bas += k; 
    }
    if(bas == 1) x++;
    int mx = 0;
    // cout << bas << " " << mx << endl;
    for(BI i = bas, tmp = x; i <= x; i *= (k + 1), mx++);
    ll nw = bas;
    rep(i, 1, mx - 1) nw *= (k + 1);
    rep(i ,1, n) {
        if(x < bas || x == 0) {
            bas = x;
            break;
        }
        if(s[i] == '*') ans[i] = 0;
        if(S[i] > mx) continue;
        int j = 0;
        for(; nw * (j + 1) <= x && j < k; j++);
        // cout << i << " " << nw << " " << j << '\n';
        x -= nw * j;
        ans[i] = j; 
        nw /= (k + 1);
    }
    rep(i, 1, n) {
        if(s[i] == '*')while(ans[i]--) cout << (s[i] == 'a' ? 'a' : 'b');
        else cout << 'a';
    }
    while(bas-- > 0) cout << 'b';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
} 