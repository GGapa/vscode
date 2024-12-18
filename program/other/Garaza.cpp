// 16:05
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define let const auto
using namespace std;
using LL = long long;
using VI = vector<int>;


constexpr int N = 1e5 + 5;
int A[N];

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    LL val[N << 2];
    vector<pair<int, int>> suf[N << 2], pre[N << 2];
    int n;
    void pushup(int x, int l, int r) {
        int mid = l + r >> 1;
        pre[x] = pre[ls];
        if(!pre[x].empty() && pre[x].back().second == mid) {
            for(auto  &p : pre[rs]){
                int g = __gcd(pre[x].back().first, p.first);
                if(pre[x].back().first == g) pre[x].back().second = p.second;
                else{
                    if(g == 1) break;
                    pre[x].emplace_back(g,p.second);
                }
            }
        }

        suf[x] = suf[rs];
        if(!suf[x].empty() && suf[x].back().second == mid + 1) {
            for(auto &p : suf[ls]){
                int g = __gcd(suf[x].back().first, p.first);
                if(suf[x].back().first == g) suf[x].back().second = p.second;
                else{
                    if(g == 1) break;
                    suf[x].emplace_back(g, p.second);
                }
            }
        }  
        val[x] = val[ls] + val[rs];
        int ltl = mid + 1;
        for(auto &pl : suf[ls]){
            int ltr = mid;
            for(auto &pr : pre[rs]){
                if(__gcd(pl.first, pr.first) != 1) 
                    val[x] += 1ll * (ltl - pl.second) * (pr.second - ltr);
                else break;
                ltr = pr.second;
            }
            ltl = pl.second;
        }
    }

    void apply(int x, int v, int l) {
        vector<pair<int, int>>(0).swap(pre[x]);
        vector<pair<int, int>>(0).swap(suf[x]);
        val[x] = 0;
        if(v == 1) return ;
        pre[x].emplace_back(v, l);
        suf[x].emplace_back(v, l);
        val[x] = 1;
    }
    void build(int x = 1, int l = 1, int r = n) {
        if(l == r) return apply(x, A[l], l);
        const int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x, l, r);
    }
    void init(int nn) {n = nn; build(); }
    void modify(int it, int v, int x = 1, int l = 1, int r = n) {
        if(l == r) return apply(x, v, l);
        const int mid = l + r >> 1;
        if(it <= mid) modify(it, v, ls, l, mid);
        else modify(it, v, rs, mid + 1, r);
        pushup(x, l, r);
    }
    LL query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return val[x];
        const int mid = l + r >> 1;
        LL res = 0;
        if(L <= mid) res += query(L, R, ls, l, mid);
        if(mid < R) res += query(L, R, rs, mid + 1, r);
        if(L <= mid && mid < R) {
            int ltl = mid + 1;
            for(auto &pl : suf[ls]){
                int ltr = mid;
                for(auto &pr : pre[rs]){
                    if(__gcd(pl.first, pr.first) != 1) res += 1ll * (ltl - max(L, pl.second)) * (min(R, pr.second) - ltr);
                    else break;
                    if(pr.second >= R) break;
                    ltr = pr.second;
                }
                if(pl.second <= L) break;
                ltl = pl.second;
            }
        }
        return res;
    }
}
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    rep(i, 1, n) cin >> A[i];
    SGT::init(n);

    for(int op, l, r; q--; ) {
        cin >> op >> l >> r;
        if(op == 1) SGT::modify(l, r);
        else cout << SGT::query(l, r) << '\n';
    }
    return 0;
}