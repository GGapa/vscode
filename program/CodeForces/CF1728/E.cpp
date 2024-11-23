#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) return x = 1, y = 0, a;
    int t = exgcd(b, a % b, y, x) ;
    y -= a / b * x;
    return t;
}

void solve() {  
    int n; cin >> n;
    LL sum = 0;
    vector<LL> A(n + 1), B(n + 1), C(n + 1);
    rep(i, 1, n) cin >> A[i] >> B[i], C[i] = B[i] - A[i], sum += A[i];
    sort(C.begin() + 1, C.end(), greater<>()) ;
    rep(i, 1, n) C[i] += C[i - 1];
    int q; cin >> q;
    for(int a, b; q--; ) {
        cin >> a >> b;
        int x, y, g = exgcd(a, b, x, y); 
        if(n % g) {cout << -1 << '\n'; continue; } 
        int dx = b / g, dy = a / g;
        x *= n / g, y *= n / g;
        int mn, mx, l, r;
        mn = (y % dy + dy) % dy;
        x = (x % dx + dx) % dx;
        mx = (n - a * x) / b;
        if(mn > mx) {cout << -1 << '\n'; continue;}
        l = 0; r = (mx - mn) / dy;
        auto f = [&](int x) {return (mn + x * dy) * b; }; 
        while(r - l > 2) {
            int mid1 = l + (r - l) / 3, mid2 = l + (r - l) / 3 * 2;
            if(C[f(mid1)] <= C[f(mid2)]) l = mid1;
            else r  = mid2;
        }
        LL ans = LLONG_MIN;
        rep(i, l, r) ans = max(ans, C[f(i)]);
        cout << sum + ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}