// 质因数的个数T3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e6 + 5;

int mn[N];
vector<int> p(1);
bitset<N> vis; 

void init() {
    rep(i, 2, N - 5) {
        if(!vis[i]) {
            p.push_back(i);
            mn[i] = i;
        }
        for(int j = 1, t; j < p.size() && (t = p[j] * i) <= N - 5 ;j++) {
            vis[t] = 1;
            mn[t] = p[j];
            if(i % p[j] == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int n, m; cin >> n >> m;
    int ans = 0;
    rep(i, n, m) {
        int cnt = 0, x = i; 
        while(x > 1) x /= mn[x], cnt++;
        
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
} 