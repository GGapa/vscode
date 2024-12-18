/*
树状数组区间修改，区间查询
P3372 【模板】线段树 1
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long

int n, m;

struct tree {
    int t[N];
    void modify(int x, int v) {
        for(; x; x -= x & -x)
            t[x] += v;
    }
    int qurey(int x) {
        int tmp = 0;
        for(; x <= n; x += x & -x)  tmp += t[x];
        return tmp;
    }
}bit1, bit2;

void modif(int x, int v) {
    bit1.modify(x, (x - 1) * v); bit2.modify(x, v);
}

int qure(int y) {
    return bit2.qurey(y) * (y) - bit1.qurey(y);
}

void modify(int l, int r, int v) {
    modif(l ,v); modif(r + 1, -v);
}

int qurey(int l, int r) {
    return qure(r) - qure(l  - 1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v = 0; i <= n; i++) {
        cin >> u;
        v = u - v;
        bit1.modify(i, (i - 1) * v);
        bit2.modify(i, v);
        v = u;
    }
    while(m--) {
        int op, x, y, z;
        cin >> op;
        if(op == 1) {
            cin >> x >> y >> z;
            modify(x, y, z);
        }
        else {
            cin >> x >> y ;
            cout << qurey(x, y) << '\n';
        }
    }
    return 0;
}