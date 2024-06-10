//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int unsigned long long
using VI = vector<int>;
const int N = 1e6 + 5;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    int ask(int x) {
        ll res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> cnt(N);
    BIT T(N);
    for(int i = 1, x; i <= n; i++) 
        cin >> x, cnt[x]++, T.add(x, 1);
    ll ans = 0;
    rep(i, 1, N - 1) if(cnt[i]) {
        int x = i;
        ans += cnt[i] * (cnt[i] - 1) / 2;
        ll lt = T.ask(x);
        
        rep(j, 2, N - 1) {
            int nw = min(x * j - 1, N - 1);
            ll t = T.ask(nw), ad = (j - 1) * cnt[i] * (t - lt);
            ans += ad;
            lt = t;
            if(nw == N - 1) break;
        }
    }
    cout << ans << '\n';
    return 0;
}