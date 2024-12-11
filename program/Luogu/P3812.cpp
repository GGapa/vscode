#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

struct Line {
    vector<int> a;
    int n;
    Line(int _n) : n(_n), a(_n + 1) {}
    void insert(int x) {
        per(i, n, 0)
         if(x >> i & 1) {
            if(!a[i]) return a[i] = x, void();
            else x ^= a[i];
        }
    }
    int query() {
        int ret = 0;
        per(i, n, 0) if(!(ret >> i & 1)) ret ^= a[i];
        return ret;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    Line bs(51);
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        bs.insert(x);
    }
    cout << bs.query() << '\n';
    return 0;
}