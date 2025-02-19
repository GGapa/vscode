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
    
    cout << rng(1, 20000) << " " << rng(1, 20000) << '\n';

    return 0; 
}