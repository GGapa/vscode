#include <bits/stdc++.h>
using namespace std;

int x, n;

void solve() {
    cin >> x >> n;
    int ans = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i != 0) continue;
        if(n <= x / i)
            ans = max(ans,i );
        if(n <= i)           
            ans = max(ans, x / i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}