#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int n, k;

struct BIT {
    int T[501][5505];
    int lowbit(int x) {return x & -x; }
    void add(int x, int y, int v) {
        x++;
        assert(x != 0 && y != 0);
        for(; x <= k + 1; x += lowbit(x)) 
            for(; y <= 5500; y += lowbit(y))
                T[x][y] = max(T[x][y], v);
    }
    int ask(int x, int y) {
        int ret = 0;
        for(; x; x -= lowbit(x)) 
            for(; y; y -= lowbit(y)) 
                ret = max(ret, T[x][y]);
        return ret;
    }
};

BIT T;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i];
    vector<VI> F(n + 1, VI(k + 1)) ;
    int ans = 0;
    rep(i, 1, n) rep(j, 0, k) {
        auto &f = F[i][j] ;
        f = max(f, T.ask(j, A[i] + j) + 1);
        T.add(j, A[i] + j, f);
        ans = max(ans, f);
        cout << i << " " << j << " " << f << '\n';
    }
    cout << ans << '\n';
    return 0;
}
