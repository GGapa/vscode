#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

vector<int> A(1);

#define ls (x << 1)
#define rs ((x << 1) | 1)
struct SegTree{
    int n;
    struct Node {
        int ty = -1, tag; 
        LL sum = 0, val = 0;
    };
    vector<Node> T;
    void bulid(int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(l == r) return T[x].val = A[l], void();
        int mid = l + r >> 1;
        bulid(ls, l, mid); bulid(rs, mid + 1, r) ;
        T[x].val = T[ls].val + T[rs].val;
    }
    SegTree(int _n) : n(_n), T(n << 2) {bulid();}
    void update(int x, int ty) {
        auto &t = T[x];
        t.ty = t.tag = ty;
        t.sum = (ty == 1 ? t.val : 0);
    }
    void pushdown(int x) {
        if(T[x].ty == -1) return ;
        update(ls, T[x].ty); update(rs, T[x].ty);
        T[x].ty = -1;
    }
    void modify(int L, int R, int v, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) return update(x, v);
        pushdown(x);
        int mid = l + r >> 1;
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
        T[x].sum = T[ls].sum + T[rs].sum;
    }
    LL query(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) return T[x].sum;
        pushdown(x);
        int mid = l + r >> 1;
        LL ret = 0;
        if(L <= mid) ret += query(L, R, ls, l, mid);
        if(mid < R) ret += query(L, R, rs, mid + 1, r);
        return ret;
    }
};
#undef ls
#undef rs

vector<pair<int, int>> blo[N], que[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> ti(m + 1), wt(n + 1), P(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> ti[i] >> P[i];
        if(wt[P[i]]) blo[P[i]].push_back({wt[P[i]], i - 1}), wt[P[i]] = 0;
        else wt[P[i]] = i;
        if(i == 1) continue;
        A.push_back(ti[i] - ti[i - 1]);
    }
    SegTree T(m);
    int q; cin >> q;
    vector<int> ans(q + 1);
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y; 
        if(blo[x].size() < blo[y].size()) swap(x, y);
        que[x].push_back({y, i}) ;
    }
    auto work = [&](int x, int ty) {
        for(auto p : blo[x]) T.modify(p.first, p.second, ty);
    };
    auto ask = [&](int x) {
        LL ret = 0;
        for(auto p : blo[x]) ret += T.query(p.first, p.second) ;
        return ret;
    };
    vector<int> id(n + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
        return blo[x].size() > blo[y].size(); 
    });
    rep(c, 1, n) {
        int i = id[c];
        if(!que[i].empty()){
            work(i, 1);
            for(auto p : que[i]) {
                int j = p.first, ii = p.second; 
                ans[ii] += ask(j);    
            }
            work(i, 0);
        }
    }
    rep(i, 1, q) cout << ans[i] << "\n";
    return 0;
}