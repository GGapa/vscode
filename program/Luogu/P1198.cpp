#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mod ;

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn;
        tr.assign(n + 5, T{});
    }
    BIT (int nn = 0) {
        init(nn);
    }
    void add(int x, const T &v) {
        for(++x; x <= n; x += x & -x) tr[x] = max(tr[x], v);
    }
    T ask(int x) {
        T ret{};
        for(++x; x >= 1; x -= x & -x) ret = max(ret, tr[x]);
        return ret;
    }
    T query(int l, int r) {
        return ask(r) - ask(l);
    }
};



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q >> mod;
    int now = 2e5;
    BIT<LL> tr(now + 10);
    LL lstans = 0;
    while(q--) {
        char c; cin >> c;
        LL v; cin >> v;
        if(c == 'A') {
            tr.add(--now, (v + lstans) % mod);
        }
        else {
            lstans = tr.ask((now + v - 1));
            cout << lstans << '\n';
        }
    }    
    return 0;
}