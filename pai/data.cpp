#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

random_device gen;

mt19937 rnd(gen());

int rng(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rnd);
}

signed main() {
    freopen("data.in", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n = 10;
    cout << n << '\n';
    rep(i, 1, n) {
        int l = rng(1, n), r = rng(1, n);
        if(l > r) swap(l, r);
        cout << l << " " << r << '\n';
    }
    return 0;
}
/*
g++ data.cpp -o data
*/