#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), ltpos(n + 1), vis(n + 1);
    rep(i ,1, n) cin >> A[i], ltpos[A[i]] = max(ltpos[A[i]], i) ;
    vector<int> ps;
    rep(i, 1, n) if(ltpos[i]) ps.push_back(ltpos[i]) ;
    vector<int> ans;
    auto update = [&](int l, int r, int len, int nw) {
        multiset<pair<int, int>> mx, mn;
        rep(i, l, r) 
            mx.insert({-A[i], i}), mn.insert({A[i], i}) ;   //不要忘记这里有负号！！！
        while(!mx.empty() || !mn.empty()) {
            while(!mx.empty() && (vis[-mx.begin()->first] || mx.begin()->second < l)) mx.erase(mx.begin()) ;
            while(!mn.empty() && (vis[mn.begin()->first] || mn.begin()->second < l)) mn.erase(mn.begin()) ;
            int v, it;
            if(mx.empty() && mn.empty()) break;
            if(len & 1) v = -mx.begin()->first, it = mx.begin()->second;
            else v = mn.begin()->first, it = mn.begin()->second;
            vis[v] = 1; ans.emplace_back(v); l = it + 1; len++;
            if(v == nw) return l;
        }
        return l;
    };
    int lst = 1;
    sort(ps.begin(), ps.end()) ;
    for(auto ii : ps) if(!vis[A[ii]]) {
        lst = update(lst, ii, ans.size() + 1, A[ii]) ;
        if(vis[A[ii]]) continue;
        ans.emplace_back(A[ii]); vis[A[ii]] = 1;
    }
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
5 2 1 7 9 7 2 5 5 2
5 5 5 4 4 3 2 2 2 1
*/