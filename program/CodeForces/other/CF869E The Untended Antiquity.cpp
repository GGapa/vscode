#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using ULL = unsigned long long ;
const int N = 2500 + 5;

int n, m;


struct BIT {
    ULL T[N][N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int y, int v) {
        for(int i = x; i <= n; i += lowbit(i)) 
            for(int j = y; j <= m; j += lowbit(j)) 
                T[i][j] ^= v;
    }
    ULL ask(int x, int y) {
        ULL ret = 0;
        for(int i = x; i; i -= lowbit(i)) 
            for(int j = y; j; j -= lowbit(j)) 
                ret ^= T[i][j];
        return ret;
    }
    ULL query(int x, int y) {return ask(x, y) ; } 
    void add(int a, int b, int x, int y, ULL c) {
        add(a, b, c);
        add(a, y + 1, c);
        add(x + 1, b, c);
        add(x + 1, y + 1, c);
    }
}T; 

map<tuple<int, int, int, int>, ULL> mp;
mt19937_64 rd(time(0));

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        int a, b, x, y; cin >> a >> b >> x >> y;
        if(op == 1) {
            auto t = rd();
            mp[{a, b, x, y}] =  t;
            T.add(a, b, x, y, t);
        }
        else if(op == 3) 
            cout << (T.query(a, b) == T.query(x, y) ? "Yes\n" : "No\n");
        else 
            T.add(a, b, x, y, mp[{a, b, x, y}]);
    }
    return 0;
}