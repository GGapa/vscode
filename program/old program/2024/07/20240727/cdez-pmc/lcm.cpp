#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e5 + 5;

int A[N];
signed main() {
    freopen("lcm.in", "r", stdin);
    freopen("lcm.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int mx = 0 ;
    for(int i = 1, x; i <= n; i++) 
        cin >> x, A[x] = 2, mx = max(mx, x);
    int ans = 0;
    for(int i = 2; i <= mx; i++) if(A[i] == 2) {
        int t = i - 1;
        ans++;
        for(int j = i; j <= mx; j += t) A[j] = 1;
    }
    ans = max(ans, 1);
    cout << ans << '\n';
    return 0;
}