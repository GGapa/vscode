#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct BIT {
    int n;
    vector<LL> T;
    BIT(int _n) : n(_n + 1) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(++x; x > 0; x -= lowbit(x)) (T[x] = max(T[x], 1ll * v));
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(++x; x <= n; x += lowbit(x)) (res = max(res, T[x]));
        return res;
    }
    LL query(int l, int r) {
        if(l > r) return 0;
        return ask(r) - ask(l - 1); 
    }
    void clear() {fill(T.begin(), T.end(), 0); }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    BIT tr(30);
    vector<int> F(n + 1) ;
    int cnt = 0;
    rep(i, 1, n) {
        int c = s[i] - 'a';
        int mx = tr.ask(c + 1) + 1; 
        F[i] = mx;
        cnt = max(cnt, mx) ;
        tr.add(c, mx) ;
    }
    cout << cnt << '\n';
    rep(i, 1, n) cout << F[i] << " \n"[i == n];
    return 0; 
}