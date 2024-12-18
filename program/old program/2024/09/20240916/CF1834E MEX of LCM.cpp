#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

LL lcm(int x, int y) {return 1ll * x / __gcd(x, y) * y; }

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    set<int> a, b; 
    const int INF = 1e9;
    per(i, n, 1) {
        set<int> tmp;
        for(auto t : a) if(lcm(t, A[i]) <= INF) tmp.insert(lcm(t, A[i]));
        tmp.insert(A[i]);
        swap(tmp, a);
        for(auto t : a) b.insert(t);
    }
    int nw = 1;
    for(auto t : b) {
        if(t == nw) nw++;
        else return cout << nw << '\n', void();
    }
    cout << nw << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}