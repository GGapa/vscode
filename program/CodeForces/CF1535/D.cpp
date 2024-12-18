//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

struct Node {
    int fa, ls, rs, id, cnt = 1;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> m;
    n = (1 << m);
    string s; cin >> s;
    s = " " + s;
    vector<Node> A(n + 1); 
    
    for(int pw = 1, tmp = 1; pw <= m; pw++) {
        for(int i = tmp; i < tmp + (1 << (m - pw)); i++) {
            auto &a = A[i];
            a.id = i;  a.cnt = 1; a.fa = tmp + (1 << (m - pw)) + (i - tmp) / 2;
            if((i - tmp) % 2) A[a.fa].rs = i;
            else  A[a.fa].ls = i;
        }
        tmp += (1 << (m - pw));
    }
    int q; cin >> q;  
    function<void(int)> dfs = [&](int x) {
        auto &a = A[x];
        if(s[x] == '0') a.cnt = A[a.ls].cnt;
        else if(s[x] == '1')a.cnt = A[a.rs].cnt;
        else a.cnt = A[a.ls].cnt + A[a.rs].cnt;
        if(a.fa >= n) return;

        dfs(a.fa);
    };
    rep(i, 1, (1 << (m - 1))) dfs(i);
    for(int p, o = 1; o <= q; o++) {
        char c; cin >> p >> c;
        s[p] = c;
        dfs(p);
        cout << A[n - 1].cnt << '\n';
    }
    return 0; 
}

