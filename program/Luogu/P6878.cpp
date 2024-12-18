#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s; s = " " + s + " ";
    vector<int> s1(n + 2), s2(n + 2), s3(n + 2);
    rep(i, 1, n + 1) {
        s1[i] = s1[i - 1] + (s[i] == 'J');
        s2[i] = s2[i - 1] + (s[i] == 'O');
        s3[i] = s3[i - 1] + (s[i] == 'I');
    }
    int ans = INT_MAX;
    for(int i = 1, j = 1, x = 1, y = 1; i <= n; i++) {
        while(j <= n && s1[j] - s1[i - 1] < k) j++;
        x = max(x, j + 1);
        while(x <= n && s2[x] - s2[j] < k) x++;
        y = max(y, x + 1);
        while(y <= n && s3[y] - s3[x] < k) y++;
        if(s1[j] - s1[i - 1] < k || s2[x] - s2[j] < k || s3[y] - s3[x] < k) break;
        ans = min(ans, y - i - 3 * k + 1);
    }
    if(ans >= INT_MAX) ans = -1;
    cout << ans << '\n';
    return 0; 
}
/*
10 1
OJIJOIOIIJ
*/