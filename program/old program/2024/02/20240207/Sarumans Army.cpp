//Saruman's Army
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int R, n; cin >> R >> n && R != -1 && n != -1; ) {
        vector<int> a(n + 1);
        rep(i, 1, n) cin >> a[i];
        sort(begin(a), end(a));
        int ans = 0;
        for (int i = 1, r = -1; i <= n; i++) {
            int x = a[i]; 
            if (x <= r) continue;
            while (i + 1 < n && a[i + 1] <= x + R) ++i;
            ++ans, r = a[i] + R;
        }      
        cout << ans << '\n';
    }
    return 0;
}