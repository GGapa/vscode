#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout);
    int n; cin >> n;
    queue<int> q;
    multiset<int> s;
    for(int i = 1, x; i <= n; i++) 
        cin >> x, s.insert(x), q.push(x);
    int ans = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == *s.rbegin()) s.erase(--s.end());
        else q.push(x);
        ans++;
    }
    cout << ans - n << '\n';
    return 0;
}
/*

*/