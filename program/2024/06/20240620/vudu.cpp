#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct BIT {
    int n ;
    vector<ll> T;
    BIT(int _n) : n(_n), T(_n + 5) {}
    int lowbit(int x) {return x & -x; }
    void add(int x, int v) { for(; x; x -= lowbit(x)) T[x] += v; }
    int ask(int x) { 
        ll ret = 0;
        for(; x <= n; x += lowbit(x)) ret += T[x];
        return ret;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("A.in", "r", stdin);
    int n; cin >> n;
    vector<int> A(n + 1);
    vector<ll> S(n + 2);
    rep(i, 1, n) cin >> A[i];
    int p ; cin >> p;
    per(i, n + 1, 1) S[i] = S[i + 1] + (A[i] - p);
    vector<ll> B = S;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()));
    int m = B.size();
    BIT T(m);
    ll ans = 0;
    rep(i, 1, n + 1) S[i] = lower_bound(B.begin(), B.end(), S[i]) - B.begin() + 1;
    rep(i, 1 ,n) {
        T.add(S[i], 1);
        ans += T.ask(S[i + 1]);
    }
    cout << ans << endl;
    return 0;
}