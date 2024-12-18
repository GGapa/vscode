// P3870 [TJOI2009] 开关
// https://www.luogu.com.cn/problem/P3870
// 2023-11-14 09:39
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
struct Node {
    int l, r, add, sum;
}t[maxn * 4];
int op, ll, rr;

int lson(int x) {return x * 2;}
int rson(int x) {return x * 2 + 1;}

void push(Node& x, Node& lson, Node& rson) {
    if(!x.add) return;
    lson.sum = lson.r - lson.l - lson.sum + 1;
    rson.sum = rson.r - rson.l - rson.sum + 1;
    lson.add ^= 1; rson.add ^= 1;
    x.add = 0;
}

void bulid(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    if(l == r) return ;
    int mid = l + r >> 1;
    bulid(lson(x), l, mid);
    bulid(rson(x), mid + 1, r);
}

void change(int x, int l, int r) {
    if(l <= t[x].l && t[x].r <= r) {
        t[x].sum = t[x].r - t[x].l - t[x].sum + 1;
        t[x].add ^= 1;
        return ;
    }
    push(t[x], t[lson(x)], t[rson(x)]);
    int mid = t[x].l + t[x].r >> 1;
    if(ll <= mid) change(lson(x), l, r);
    if(rr > mid) change(rson(x), l, r);
    t[x].sum = t[lson(x)].sum + t[rson(x)].sum;
}

int query(int x, int l, int r)  {
    if(l <= t[x].l && t[x].r <= r) 
        return t[x].sum;
    push(t[x], t[lson(x)], t[rson(x)]);
    int mid = t[x].l + t[x].r >> 1;
    int tmp = 0;
    if(l <= mid) tmp += query(lson(x), l, r);
    if(r > mid) tmp += query(rson(x), l, r);
    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bulid(1, 1, n);
    while(m--) {
        cin >> op >> ll >> rr;
        if(op) {

            cout << query(1, ll, rr) << '\n';
        }
        else {
            change(1, ll, rr);
        }
    }
    return 0;
}