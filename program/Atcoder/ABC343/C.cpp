// C
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    // itoa
    int ans = 1; 
    string s, s1 = " ";
    for(int i = 2; i * i * i <= n; i++) {
        int t = 1ll * i * i * i;
        s = to_string(t); s1 = s;
        reverse(s1.begin(), s1.end());
        if(s == s1) 
            ans = max(ans, t);
    }
    cout << ans << '\n';
    return 0;
}