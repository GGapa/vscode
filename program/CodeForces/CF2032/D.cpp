#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

int ask(int u, int v) {
    int ret = -1;
    cout << "? " << u << " " << v << '\n';
    cout.flush();
    cin >> ret;
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> fa(n + 1, -1);
    fa[1] = 0;
    vector<int> a(1, 1);
    rep(i, 2, n) {
        if(ask(1, i) == 0) {
            fa[i] = 1;
            break;
        }
        fa[i] = 0;
        a.emplace_back(i);
    }
    vector<int> b; b.emplace_back(a.back() + 1);
    for(int i = a.back() + 2, j = 1; i < n; i++) { 
        while(j < a.size() && ask(a[j], i)) j++;    
        if(j >= a.size()) a = b, b.clear(), i--, j = 0;
        else {
            fa[i] = a[j]; j++;
            b.emplace_back(i);
        }
    }
    cout << "! ";
    rep(i, 1, n - 1) cout << fa[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
使用最多 (n - 1) 次查询可以询问出 0 节点有多少个孩子
*/