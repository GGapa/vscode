//  Why Did the Cow Cross the Road II S
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n + 1);
    for(int i = 1, x; i <= m; i++) 
        cin >> x, a[x]++;
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    int ans = INT_MAX;
    rep(i, 1, n - k) ans = min(ans, a[i + k] - a[i]);
    cout << ans << '\n';
    return 0;
}