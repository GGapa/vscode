//Add All
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int n; cin >> n && n; ) {
        int ans = 0;
        rep(i, 1, n ) {
            int x; cin >> x;
            q.push(x);
        }
        while(q.size() > 1) {
            int a = q.top();q.pop();
            int b = q.top(); q.pop();
            ans += (a + b); q.push(a + b);
        }
        q.pop();
        cout << ans << '\n';
    }
    return 0;
}