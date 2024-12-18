#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

int n, m; 

struct Tree {
    int mx = 31;
    static const int N = 5e5 + 5;
    struct Node {
        int cnt = 0, id;
        int s[2];
    };
    Node tr[N << 6]; 
    int idx = 0;
    int insert(int lt, LL v, int id, int it = -2) {
        if(it == -2) it = mx;
		int nw = ++idx;
        tr[nw] = tr[lt]; tr[nw].cnt++;
        if(it < 0) {
            return tr[nw].id = id, nw;
        }
        int i = v >> it & 1;
        tr[nw].s[i] = insert(tr[lt].s[i], v, id, it - 1);
		return nw;
    } 
    LL query(int x, int y, LL v, int it = -2) {
        if(it == -2) it = mx;
        if(it < 0) {
            return tr[y].id;
        }
        int i = v >> it & 1;
        if(tr[tr[y].s[!i]].cnt > tr[tr[x].s[!i]].cnt) 
            return query(tr[x].s[!i], tr[y].s[!i], v, it - 1) ;
        else return query(tr[x].s[i], tr[y].s[i], v, it - 1);
    }
}T;

LL A[N];
int rt[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> A[i], A[i] ^= A[i - 1];
    rep(i, 1, n) rt[i] = T.insert(rt[i - 1], A[i], i);

    using AI = tuple<LL, int, int, int, int>;
    priority_queue<AI> q;
    rep(i, 0, n - 1) {
        int t = T.query(rt[i], rt[n], A[i]);
        q.push({A[t] ^ A[i], i, i + 1, n, t});
    }

    LL ans = 0;
    while(!q.empty() && m--) {
        auto tmp = q.top(); q.pop();
        int i, l, r, ot;
        LL ttt;
        tie(ttt, i, l, r, ot) = tmp; ans += ttt;
        if(ot != l) {
            int t = T.query(rt[l - 1], rt[ot - 1], A[i]);
            q.push({A[t] ^ A[i], i, l, ot - 1, t});
        }
        if(ot != r) {
            int t =    T.query(rt[ot], rt[r], A[i])  ;      
            q.push({A[t] ^ A[i], i, ot + 1, r, t});
        }
    }
    cout << ans << '\n';
    return 0;
}