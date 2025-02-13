#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
#define int long long
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn + 1;
        tr.assign(n + 5, T{});
    }
    BIT (int nn = 0) {
        init(nn);
    }
    void add(int x, const T &v) {
        for(++x; x <= n; x += x & -x) tr[x] = (tr[x] + v);
    }
    T ask(int x) {
        T ret{};
        for(++x; x >= 1; x -= x & -x) ret = (ret + tr[x]);
        return ret;
    }
    T query(int l, int r) {
        return ask(r) - ask(l);
    }
};

constexpr int N = 1e6 + 5, LG = __lg(N) + 1;

struct ST {
    int n;
    vector<VI> ma;

    vector<int> &operator[](const int x) {return ma[x]; }
    const vector<int> &operator[](const int x) const {return ma[x]; }
    ST (int nn, int val) {
        n = nn;
        ma.assign(n + 1, VI(__lg(n) + 1, val));
    }
    void init() {
        rep(j, 1, __lg(n)) for(int i = 1; i + (1 << j) - 1 <= n; i++) 
            ma[i][j] = max(ma[i][j - 1], ma[i + (1 << j - 1)][j - 1]);
    }
    int query(int l, int r) {
        assert(l <= r); 
        int d = __lg(r - l + 1);
        return max(ma[l][d], ma[r - (1 << d) + 1][d]);
    }
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, E; cin >> n >> E;
    vector<int> A(n + 1), B(n + 1), V(n + 1), ns(n + 1);
    vector<LL> S(n + 1), tmp;
    rep(i, 1, n) cin >> A[i];    
    rep(i, 1, n) cin >> B[i], V[i] = B[i] - A[i], S[i] = S[i - 1] + V[i]; 
    tmp = S;
    tmp.emplace_back(1);
    sort(tmp.begin() + 1, tmp.end()); 
    rep(i, 0, n) ns[i] = lower_bound(tmp.begin() + 1, tmp.end(), S[i]) - tmp.begin();

    ST ma(n, 0), mb = ma;
    rep(i, 1, n) (V[i] > 0 ? ma[i][0] = A[i] : mb[i][0] = B[i]);
    ma.init(), mb.init();

    LL ans = 0, sum = (V[1] < 0 ? V[1] : 0);
    BIT<int> tr(n + 2);
    for(int i = 1, j = 1; i <= n; i++) {
        int lt = j;
        while((j < i) || (j <= n && E + sum >= ma.query(i, j) && E + sum >= mb.query(i, j))) {
            j++;
            if(j <= n && V[j] < 0) sum += V[j];  
        }
        rep(t, lt, j - 1) tr.add(ns[t], 1);
        ans += j - i - tr.query(0, max(ns[i - 1] - 1, 0ll));
        tr.add(ns[i], -1);
        if(V[i] < 0) sum -= V[i];
    }
    cout << ans << '\n';
    return 0;
}
/*
5 1
10 10 10 10 10
100 100 100 100 100


5 0
0 0 0 0 0
5 7 9 1 10
*/