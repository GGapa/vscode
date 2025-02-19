#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), ed = (b); i <= ed; i++)
#define per(i, a, b) for(int i = (a), ed = (b); i >= ed; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

#ifdef _WIN32
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
#else
random_device gen;
mt19937 rnd(gen());
#endif

int rng(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rnd);
}

signed main() {
    freopen("data.in", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n = 1e5, m = 1e5, P = 0;
    cout << n << " " << m << "\n";

    for(int op, l, r, x; m--; ) {
        op = rng(1, 4);
        l = rng(1, n); r = rng(1, n);
        if(l > r) swap(l, r);
        if(1 <= op && op <= 3) {
            x = rng(0, 1e8);
            cout << op << " " << l << " " << r << " " << x << '\n';
        }
        else {
            x = rng(1, n);
            if(op == 4) cout << op << " " << l << " " << r << '\n';
            else cout << op << " " << x << '\n';
        }
    }

    return 0; 
}