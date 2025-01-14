#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    vector<LL> s(n + 1);
    rep(i, 1, n) cin >> A[i];
    map<int, int> mp;
    mp[0] = 1;
    LL ans = 0;
    for(int i = 1 ; i <= n ; ++ i) {
        if(i % 2) s[i] += s[i - 1] + A[i]; 
        else s[i] += s[i - 1] - A[i];
        ans += mp[s[i]] ++;
    }
    cout << ans << '\n';
    return 0;
}