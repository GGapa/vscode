#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn], n, m, ans;

void solve() {
    int ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
      cin >> a[i];
    for(int i = 1; i <= m; i++)
      cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    for(int i = 1; i <= n; i++)
      ans += abs(a[i]-b[m-i+1]);
    cout << ans << '\n';
}

int main() {
    int T; cin >> T;
    while(T--) solve();
    return 0;
}