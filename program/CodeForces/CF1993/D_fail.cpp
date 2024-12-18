#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    vector<LL> S(n + 1), ave(1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    if(n <= k) {
        sort(A.begin(), A.end()) ;
        return cout << A[(n + 1) / 2] << '\n', void();
    }
    rep(l, 1, n - k + 1) {
        int r = l + k - 1;
        ave.push_back(S[r] - S[l - 1]);
    }
    int m = ave.size() - 1;
    vector<int> id(m + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
        return ave[x] < ave[y];
    });
    BIT T(n + 1);
    int rem = n;
    rep(i, 1, m) {
        int l = id[i], r = l + k - 1;
        if(T.ask(r) - T.ask(l - 1) != 0) continue;
        rem -= k;
        T.add(l, 1);  
        if(rem <= k) break;
    }
    vector<int> B(1);
    rep(i ,1, n) if(T.ask(i) - T.ask(i - 1) == 0) {
        B.push_back(A[i]);
    }
    sort(B.begin() + 1, B.end()) ;
    m = B.size();
    cout << B[m / 2] << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}