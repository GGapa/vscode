#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

const int N = 10;

vector<int> G[1 << N + 1];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b; 
    auto add = [&](int u, int v) {
        G[u].push_back(v), G[v].push_back(u);
    };
    rep(i, 1, 511) {
        add(i, i * 2), add(i, i * 2 + 1);
        add(i * 2 + 1, i * 2);
        
    }
    return 0;
}