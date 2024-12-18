#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 5000 + 5;
typedef pair<int, int> pii;

int n, f[N];
pii a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    int ans = 0;
    rep(i, 1, n) rep(j, 1, i - 1) if(a[j].second > a[i].second) 
        f[i] = max(f[i], f[j] + 1), ans = max(f[i], ans);

    cout << ans + 1 << '\n';
    return 0;
}