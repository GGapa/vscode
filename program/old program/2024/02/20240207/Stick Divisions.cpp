//Stick Divisions
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> n >> m;
    for(int i = 1, x; i <= m; i++){
        cin >> x;
        q.push(x);
    }
    ll ans = 0;
    for(int a, b; q.size() > 1; q.push(a + b)) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        ans += a + b;
    }
    cout << ans << '\n';
    return 0;
}