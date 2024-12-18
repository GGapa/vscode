#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
typedef long long ll;
using VI = vector<int>;
const int N = 1e6 + 1;

vector<int> pri;
bool vis[N + 5];
int mn[N + 5];

void init() {
    rep(i, 2, N) {
        if(!vis[i]) {pri.emplace_back(i), mn[i] = i;}
        for(auto p : pri) {
            if(p * i > N) break;
            mn[p * i] = p;
            vis[p * i] = 1;
            if(i % p == 0) break;
        }
    }
}

vector<int> A[N + 1];

void solve() {
    int n, k; cin >> n >> k;
    vector<int> B(2 * n);
    unordered_set<int> P;
    int _1 = 0;
    rep(i, n, 2 * n - 1) cin >> B[i], (i == n ? B[i] : B[(i - n)]) = B[i], _1 += (B[i] == 1);
    int ans = _1 * n;
    int m = 2 * n - 1;
    vector<int> fa(m + 1);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find= [&](int x) {return (x == fa[x] ? x : fa[x] = find(fa[x]));};
    rep(i, 1, m) {
        int x = B[i];
        while(x > 1) {
            P.insert(mn[x]);
            A[mn[x]].emplace_back(i);
            x /= mn[x];
        }
    }
    for(auto p : P) {
        sort(A[p].begin(), A[p].end());
        A[p].erase(unique(A[p].begin(), A[p].end()), A[p].end());
        int l = -1;
        for(auto r : A[p]) {
            if(l == -1) { l = r; continue; }
            int x = find(l), y = find(r);
            if(r - l <= k && x != y) fa[x] = fa[y] = y;
            l = r;
        }
        A[p].clear();
    }
    rep(i, 1, m) if(B[i] != 1) ans += (fa[i] == i);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T; cin >> T;
    while(T--) solve();
    return 0;
}