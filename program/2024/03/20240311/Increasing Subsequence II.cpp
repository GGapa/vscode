// Increasing Subsequence II
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

struct BIT {
    int n; 
    vector<ll> T;
    BIT(int _n) : n(_n), T(_n + 2) {}
    int lowbit(int x) {return x & -x;}
    void modify(int x, int v) {
        for(; x <= n; x += lowbit(x)) T[x] += v;
    }
    ll query(int x) {
        ll sum = 0;
        for(; x; x -= lowbit(x)) (sum += T[x]) %= mod;
        return sum;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    vector<int> A(n);
    for(auto &a : A) cin >> a, mp[a] = 0;
    int id = 0;
    for(auto &p : mp) p.second = ++id;
    vector<ll> F(n + 1, 1);
    BIT T(n);
    rep(i, 0, n - 1) {
        int a = A[i];
        a = mp[a]; (F[i] += T.query(a - 1)) %= mod;
        T.modify(a, F[i]);
    }
    cout << T.query(n);
    return 0;
}