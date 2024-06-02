#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

set<int> s;

void work(int x, int mn) {
    int ans = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i != 0) continue;
        if(i % 2 == 0 && i / 2 + 1 >= mn) 
            s.insert(i);
        if((x / i) % 2 == 0 && x / i != i && x / i / 2 + 1 >= mn ) 
            s.insert(x / i);
    }
}

void solve() {
    s.clear();
    int n, x; cin >> x >> n;
    int t = x - n + 1;
    int ans = 0;
    if(t >= 1) 
        work(t - 1, n);
    t = x + n - 1;
    if(t >= 1) 
        work(t - 1, n);
    cout << s.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}