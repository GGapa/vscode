#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

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
    map<int, int> mp;
    vector<pair<int, int>> A(n + 1);
    for(int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        A[i] = {r, l};
        mp[l] = 0, mp[r] = 0;
    }
    sort(A.begin() + 1, A.end());
    int m = 0;
    for(auto &i : mp) i.second = ++m;
    BIT T(m + 1);
    int ans = 0;
    rep(i, 1, n) {
        int l = mp[A[i].second], r = mp[A[i].first];
        ans += T.ask(r) - T.ask(l - 1);
        T.add(r, 1);
    }
    cout << ans << '\n';
    return 0;
}