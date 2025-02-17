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

constexpr int mx = 1e9;

signed main() {
    freopen("data.in", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n = 1000, q = 1000, m;
    vector<int> h(n + 1), t(n + 1);
    rep(i, 1, n) h[i] = rng(0, mx), t[i] = rng(0, mx);
    sort(h.begin() + 1, h.end());

    vector<int> cha;
    rep(i, 1, n) cha.emplace_back(h[i] - h[i - 1]);
    cha.emplace_back(0);
    sort(cha.begin(), cha.end());
    m = rng(0, mx);

    cout << n << " " << q << " " << m << '\n';
    rep(i, 1, n) cout << h[i] << " \n"[i == n];
    rep(i, 1, n) cout << t[i] << " \n"[i == n];

    while(q--) cout << rng(1, n) << " " << rng(1, n) << '\n';

    return 0; 
}