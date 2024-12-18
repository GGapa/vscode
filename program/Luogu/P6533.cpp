#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

constexpr int mod = 1e4 + 7;

int c;

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    constexpr int N = 1e5 + 5;
    int n;

    struct Node {
        int F[21], cnt;
        Node() {
            memset(F, 0, sizeof(F));
            F[0] = cnt = 1;
        };
        int operator[](const int x) {return F[x]; }
        void update(AI t) {
            int G[21], a = t[0], b = t[1];
            rep(i, 1, 20) G[i] = (F[i - 1] * a % mod + F[i] * b % mod) % mod;
            G[0] = F[0] * b % mod;
            (cnt *= (a + b) % mod) %= mod;    
            rep(i, 0, 20) F[i] = G[i];
        }
        int getans() {
            int ret = 0;
            rep(i, 0, c - 1) (ret += F[i]) %= mod;

            return (cnt - ret + mod) % mod; 
        }
    };
    vector<AI> tr[N << 2];

    void init(int nn) {n = nn; }
    void modify(int L, int R, AI v, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x].emplace_back(v), void();
        int mid = l + r >> 1;
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
    }
    void query(int x = 1, int l = 1, int r = n, Node sta = Node{}) {
        for(auto t : tr[x]) sta.update(t);
        if(l == r) return cout << sta.getans() << '\n', void();
        int mid = l + r >> 1;
        query(ls, l, mid, sta);
        query(rs, mid + 1, r, sta);
    }
};
#undef ls
#undef rs

int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;
    vector<AI> A(n + 1);
    rep(j, 0, 1) rep(i, 1, n) cin >> A[i][j], A[i][j] %= mod;
    
    vector<int> app(n + 1, 1);
    int q; cin >> q;
    SGT::init(q);
    for(int i = 1, it, a, b; i <= q; i++) {
        cin >> it >> a >> b; a %= mod; b %= mod;
        if(app[it] != i) SGT::modify(app[it], i - 1, A[it]);
        A[it] = {a, b}; app[it] = i;
    }
    rep(i, 1, n) SGT::modify(app[i], q, A[i]);

    SGT::query();

    return 0;
}
/*
n \log n c^3 (√)
实际上我们并不需要在意转移的顺序，因为本质上这是一个背包，已经可以使用线段树维护了
当然这个想法并不是很自然
更加自然的想法是 F(i, j) 代表选了 j 个的方案数是多少，接着通过线段树分治完成。  
*/