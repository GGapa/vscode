#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    priority_queue<int> A, B;
    for(int i = 1, x; i <= n; i++) 
        cin >> x, A.push(x) ;
    for(int i = 1, x; i <= n; i++) 
        cin >> x, B.push(x) ;
    int ans = 0;
    while(A.size() && B.size()) {
        int a = A.top(), b = B.top() ;
        A.pop(); B.pop() ;
        if(a == b) continue;
        ans++;
        if(a > b) a = log10(a) + 1;
        else b = log10(b) + 1;
        B.push(b) ;A.push(a);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}