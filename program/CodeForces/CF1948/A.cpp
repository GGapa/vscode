#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    if(n % 2) {
        cout << "NO\n";
        return ;
    }   
    cout << "YES\n";
    for(int i = 1, c = 0; i <= n / 2; i++, c ^= 1) 
        cout << char(c + 'A') << char(c + 'A');
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}