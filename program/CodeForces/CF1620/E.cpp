#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 5e5 + 5, MX = 5e5;

int fa[N];

// int find(int x) {return (fa[x] == x ? x : fa[x] = find(fa[x]));}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    iota(fa, fa + 1 + MX, 0);
    int n; cin >> n;
    vector<array<int, 3>> q;
    list<int> ans;
    for(int i = 1, op, x, y; i <= n; i++, y = 0) {
        cin >> op >> x;
        if(op == 2) cin >> y;
        q.push_back({op, x, y}) ;
    }
    reverse(q.begin(), q.end());
    for(auto i : q) {
        if(i[0] == 2) fa[i[1]] = fa[i[2]];
        else ans.push_front(fa[i[1]]);
    }
    for(auto a : ans) cout << a << " ";
    return 0;
}