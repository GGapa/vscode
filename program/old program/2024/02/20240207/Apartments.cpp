//Apartments
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    sort(a.begin(), a.end());  sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 1, j = 1; i <= n && j <= m; i++) {
        while(j <= m && b[j] < a[i] - k) j++;
        if(j <= m && b[j] <= a[i] + k) j++, ans++;
    }
    cout << ans << '\n';
    return 0;
}