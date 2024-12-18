#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1, x; i <= n; i++ )
        cin >> x, q.push(x);
    while (q.size() > 1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        q.push(x + y >> 1);
    }
    cout << q.top() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}