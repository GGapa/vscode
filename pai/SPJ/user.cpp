#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

vector<AI<2>> ans, tmp;

bool tag = 0;
int dx, dy;

void add(int x, int y) {
    if(tag) swap(x, y);
    ans.push_back({x + dx, y + dy});
}

void work(int n, int m) {
    if(n > m) swap(n, m), tag ^= 1;
    if(n == 0 || m == 0) return ;
    if(n == 1) {
        rep(i, 1, m) add(n, i);
        return ;
    }
    if(n == 2) {
        for(int j = 1; j <= m; j += 2) rep(i, 1, n) add(i, j);
        return ;
    }
    for(int j = 1; j + n - 1 <= m; j += n) 
        rep(i, 1, n) add(i, j);
    if(m % n == 0) rep(i, 2, n - 1) add(i, m);
    int nn = n, nm = m % n;
    (tag ? dx : dy) += m - nm;
    work(n, nm);
}

signed main() {
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;

    work(n, m);

    cout << n << " " << m << '\n';

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) 
        cout << x << " " << y << '\n';
    
    return 0;
}