#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100 + 5;

int n, m;
int a[N][N], f[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int ans = 0;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) rep(j, 1, m)  if(a[i][j]) {
        f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
        ans = max(ans, f[i][j]);
    }
    cout << ans << '\n';
    return 0;
}