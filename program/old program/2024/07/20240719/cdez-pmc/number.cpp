#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e6 ;
int A[N + 5];

void init() {
    for(ll i = 0; i <= N; i++) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        int t = stoll(s);
        if(t + i > N) continue;
        A[t + i]++;
    }
}

void solve() {
    ll n; cin >> n;
    if(n > N) return cout << 0 << '\n', void();
    cout << A[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("number.in", "r", stdin);
    // freopen("number.out", "w", stdout);
    init();
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
