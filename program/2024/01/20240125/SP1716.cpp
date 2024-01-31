// 参考资料：https://www.luogu.com.cn/blog/zhaohaikun/solution-sp1716
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
// #define int ll

int n, q;
ll ans;
int a[N];

struct tree {
    int l, r;
    int res, sum;
    int prel, prer;
}t[N * 4];

#define ls x * 2
#define rs x * 2 + 1

tree pushup(tree L,tree R){
    tree z;
    z.sum = L.sum + R.sum;
    z.prel = max(L.prel, L.sum + R.prel);           
    z.prer = max(R.prer, R.sum + L.prer);           
    z.res = max({L.prer + R.prel, L.res, R.res});   //左边部分右端点往左的最大子段和 + 左端点往右的最大子段和。
    z.l = L.l; z.r = R.r;
    return z;
}
void bulid(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    if(l == r) {
        t[x].prel = t[x].prer = t[x].res = t[x].sum = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
    t[x] = pushup(t[ls], t[rs]);
    // cout << t[x].l << " " << t[x].r << '\n';
}

void modify(int x, int l, int r, int ch) {
    if(l <= t[x].l && t[x].r <= r) {
        t[x].prel = t[x].prer = t[x].res = t[x].sum = ch;
        return ;
    }
    int mid = (t[x].l + t[x].r) >> 1;
    if(l <= mid) modify(ls, l, r, ch);
    if(r > mid) modify(rs, l, r, ch);
    t[x] = pushup(t[ls], t[rs]);
}

tree qurey(int x, int l, int r) {
    // cout << t[x].l << ' ' << t[x].r << endl;
    if(l <= t[x].l && t[x].r <= r) {
        return t[x];
    }
    int mid = (t[x].l + t[x].r) >> 1;
    if(r <= mid) return qurey(ls, l, r);
    if(mid < l) return qurey(rs, l, r);
    return pushup(qurey(ls, l, r), qurey(rs, l, r));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bulid(1, 1, n);
    cin >> q;
    while(q--) {
        int op, x, y;
        cin >> op;
        if(op == 0) {
            cin >> x >> y;
            modify(1, x, x, y);
        }
        else {
            cin >> x >> y;
            cout << qurey(1, x, y).res << '\n';
        }
    }
    return 0;
}