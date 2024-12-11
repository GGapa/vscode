
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<int> q;
    ll ans = 0;
    vector<int> A(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> x; x -= i;
        q.push(x);
        if(q.top() != x) {
            ans += q.top() - x, q.pop(), q.push(x);
        }
        A[i] = q.top();
    }
    per(i, n - 1, 1) A[i] = min(A[i], A[i + 1]);
    cout << ans << '\n';
    rep(i, 1, n) cout << A[i] + i<< " ";
    return 0;
}