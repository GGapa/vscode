#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


struct Tree {
    int mx = 24;
    static const int N = 6e5 + 5;
    struct Node {
        int cnt = 0;
        int s[2];
    };
    Node tr[N << 6] ;
    int idx = 0;
    int insert(int lt, int v, int it = -2) {
        if(it == -2) it = mx;
		int nw = ++idx;
        tr[nw] = tr[lt]; tr[nw].cnt++;
        if(it < 0) return nw;
        int i = v >> it & 1;
        tr[nw].s[i] = insert(tr[lt].s[i], v, it - 1);
		return nw;
    } 
    int query(int x, int y, int v, int it = -2) {
        if(it == -2) it = mx;
        if(it < 0) return 0;
        int i = v >> it & 1;
        if(tr[tr[y].s[!i]].cnt > tr[tr[x].s[!i]].cnt) return (1 << it) + query(tr[x].s[!i], tr[y].s[!i], v, it - 1) ;
        else return query(tr[x].s[i], tr[y].s[i], v, it - 1);
    }
}T;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> rt(2 * n + 1);
    int tt = 0;
    rt[0] = T.insert(0, 0);
    for(int i = 1, x; i <= n; i++) {
        cin >> x;  tt ^= x;
        rt[i] = T.insert(rt[i - 1], tt); 
    }
    while(m--) {
        string op; cin >> op;
        int l, r, x;  
        if(op == "A") {
            cin >> x;
            tt ^= x; n++;
            rt[n] = T.insert(rt[n - 1], tt);
        }
        else {
            cin >> l >> r >> x;
            l--, r--;
            if(l) cout << T.query(rt[l - 1], rt[r], x ^ tt) << '\n';
            else cout << T.query(0, rt[r], x ^ tt) << '\n';
        }
    }
    return 0;
}