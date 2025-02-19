#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void fail() {cout << -1 << '\n'; exit(0); }

signed main() {
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<set<array<int, 2>>> itv(n + 1), itl(n + 1);
    vector<int> deg(n + 1), ans;
    for(int i = 1, l, r; i <= n; i++)   
        cin >> l >> r, deg[r]++, itl[l].insert({r, i}); 
    rep(i, 1, n) deg[i] += deg[i - 1];
    set<array<int, 3>> lft;
    rep(i, 1, n) {
        for(auto a : itl[i]) lft.insert({i, a[0], a[1]});
        int r;
        rep(j, i, n) {
            if(deg[j] == j) {
                r = j;
                break;
            }
            if(deg[j] > j) fail();
        }
        array<int, 3> mn = {INT_MAX, INT_MAX, INT_MAX};
        for(auto a : lft) if(a[1] <= r){
            if(a[1] < i) fail();
            if(a[2] < mn[2]) mn = a;
        }
        if(mn[0] == INT_MAX) fail();
        lft.erase(mn);
        ans.emplace_back(mn[2]);
        rep(j, i, mn[1] - 1) deg[j]++;
    }
    int cnt = 0;
    for(auto a : ans) cout << a << " ";
    cout << '\n';
    return 0;
}
/*
g++ user.cpp -o user -O2 -std=c++14 -Wall -Wextra
提意转化为：
构造一个字典序最小的排列，满足 x 在 [lx, rx] 中
*/