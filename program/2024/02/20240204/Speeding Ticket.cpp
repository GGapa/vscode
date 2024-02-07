//Speeding Ticket
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, m;
int v[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1, l, s, it = 0; i <= n; i++) {
        cin >> l >> s;
        rep(j, it, it + l - 1) v[j] = s;
        it += l;
        
    }
    int ans = 0;
    for(int i = 1, l, s, it = 0; i <= m; i++) {
        cin >> l >> s;
        rep(j, it, it + l - 1) 
            ans = max(ans, s - v[j]);
        it += l;
    }
    cout << ans;
    return 0;
}