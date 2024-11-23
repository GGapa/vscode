#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; LL m; cin >> n >> m;
    vector<int> A(n + 2) ;
    rep(i, 1, n) cin >> A[i];
    vector<int> id(n+ 1), win(n + 1);
    iota(id.begin(), id.end(), 0); win = id;
    sort(id.begin(), id.end(), [&](const int &x, const int &y) {
        if(A[x] == A[y]) return x < y;
        return A[x] < A[y];
    });
    LL sum = 0;
    int cnt = 0, mx = 0;
    rep(c, 1, n)  {
        int i = id[c];
        if(sum + A[i] > m) break;
        sum += A[i]; win[i]--; cnt++; mx = i;
    }
    int ans = 0;
    sort(win.begin() + 1, win.end(), greater<>());
    rep(i, 1, n) if(win[i] > cnt) ans = i;
    if(ans && A[cnt + 1] <= m) {
        sum = A[cnt + 1];
        iota(win.begin(), win.end(), 0);
        win[cnt + 1]--;
        int t = cnt + 1; cnt = 1; 
        rep(c, 1, n)  {
            int i = id[c];
            if(i == t) continue;
            if(sum + A[i] > m) break;
            sum += A[i]; win[i]--; cnt++; mx = i;
        }   
        t = 0;
        sort(win.begin() + 1, win.end(), greater<>());
        rep(i, 1, n) if(win[i] > cnt) t = i;
        ans = min(ans, t);
    }
    cout << ans + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}