#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

bool isprime(int x) {
    // cout << x << '\n';
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
    return true;
}

const int N = 2e5 + 5;
int F[N] = {0, 1, 2, 2, 3, 3, 4};
vector<int> use[N];

void debug(int n) {
    int cnt = 0;
    rep(i, 1, n) rep(j, i + 1, n) if(isprime(i ^ j)) cout << i << " " << j << '\n', cnt++;
    cout << cnt << '\n';
}

void solve() {
    int n; cin >> n;
    int mx = 1;
    debug(n);
    F[1] = 1; use[1].push_back(1);
    int ans = 1;
    rep(i, 2, n) {
        set<int> s;
        per(j, i - 1, 1) if(isprime(i ^ j)) s.insert(F[j]);
        int lt = 1;
        for(auto a : s) {
            if(a == lt) lt = a + 1;
            else 
                break;
        }
        F[i] = lt;
        ans = max(ans, F[i]);
    }
    cout << ans << '\n';
    rep(i, 1, n) cout << F[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}