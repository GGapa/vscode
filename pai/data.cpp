#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

random_device gen;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

int rng(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rnd);
}

signed main() {
    freopen("data.in", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n = 1000;
    cout << n << '\n';
    rep(i, 1, n) {
        int l = rng(5e5, 5e5), r = rng(5e5, 5e5);
        if(l > r) swap(l, r);
        cout << l << " " << r << '\n';
    }
    int q = 1000;
    cout << q << '\n';
    rep(i, 1, q) cout << rng(1, 5e5) << '\n';
    return 0; 
}
/*
g++ data.cpp -o data
*/
