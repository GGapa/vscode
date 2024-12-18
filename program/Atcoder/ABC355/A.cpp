#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    vector<int> A(4);
    A[a]++, A[b]++;
    int ans = 0, cnt = 0;
    rep(i, 1, 3) if(!A[i]) cnt++, ans = i;
    if(cnt > 1) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}