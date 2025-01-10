#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<array<int, 2>> itv;
    for(int i = 1, l, r ; i <= n; i++) 
        cin >> l >> r, itv.push_back({l, r});
    vector<int> id(n + 1);
    iota(id.begin(), id.end(), 0);
    vector<int> ans;
    do {
        bool tag = 1;
        rep(j, 0, n - 1) {
            auto &a = itv[j];
            bool tg = 0;
            rep(i, a[0], a[1]) if(id[i] == j + 1) tg = 1;
            if(!tg) {
                tag = 0;
                break;
            }
        }
        if(tag && (ans.empty() || id < ans)) ans = id;
    }while(next_permutation(id.begin() + 1, id.end()));
    if(ans.empty()) return cout << -1 << '\n', 0;
    rep(i, 1, n) cout << ans[i] << " ";
    cout << '\n';
    return 0;
}