#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    int ans = 0;
    vector<int> vis(n + 2);
    rep(i, 1, n) if(!vis[i] && A[i] == 2) {
        int l = i, r = i;
        while(l >= 1 && A[l]) l--;
        while(r <= n && A[r]) r++;
        rep(j, l, r) vis[j] = 1;
        ans++;
    }
    vis[0] = vis[n + 1] = 1;

    rep(i, 1, n) if(!vis[i] && A[i] == 1) {
        int l = i, r = i;
        while(l >= 1 && A[l]) l--;
        while(r <= n && A[r]) r++;
        if(vis[l] == 1) {
            vis[r] = 1;
        }
        else {
            vis[l] = 1;
        }
        rep(j, l + 1, r - 1) vis[j] = 1;
        ans++;
    }

    rep(i, 1, n) if(!vis[i]) ans++;
    cout << ans << '\n';
    return 0;
}