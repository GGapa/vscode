//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    if(*max_element(A.begin() + 1, A.end()) < 0) {
        rep(i, 1, n) cout << 1 * (1 + (i % 2)) << " \n"[i == n];
        return ;
    }
    auto LCA = [&](int x, int y) {
        vector<int> L, R;
        while(__lg(x) > __lg(y))  L.emplace_back(x)  , x /= 2;
        while(__lg(x) < __lg(y)) R.emplace_back(y), y /= 2;
        while(x != y) L.emplace_back(x), R.emplace_back(y), x /= 2, y /= 2;
        L.emplace_back(x);
        reverse(R.begin(), R.end());
        for(auto r : R) L.emplace_back(r);
        return L;
    };
    int lt =  0;
    list<int> ans;

    for(int i = 1; i <= n; i++) if(A[i] != -1){
        if(!lt) {
            for(int j = i, it = 0; j >= 1; j--, it++) ans.push_front(A[i] / (1 + it % 2));
        }
        else {
            auto t = LCA(A[lt], A[i]);
            int len = i - lt - 1;
            if(t.size() > len || (len - t.size()) % 2 == 0) return cout << "-1\n", void();
            for(auto T : t) ans.push_back(T);
            for(int j = lt + len + 1, it = 1; j <= i; j++, it++) ans.push_back(A[i] * (1 + it % 2));
        }
        lt = i;
    }
    for(int i = lt + 1, it = 1; i <= n; i++) ans.push_back(A[lt] / (1 + it % 2));
    for(auto a : ans ) cout << a <<  " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}