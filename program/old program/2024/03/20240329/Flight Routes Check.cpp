// Flight Routes Check
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

using VI = vector<int>;
void dfs(int x, vector<VI> &G, vector<int> &V) {
    V[x] = true;
    for(auto to : G[x]) if(!V[to]) {
        dfs(to, G, V);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> G1(n + 1), G2(n + 1);
    vector<int> v1(n + 1), v2(n + 1);
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, G1[x].push_back(y), G2[y].push_back(x);
    dfs(1, G1, v1);
    int t = find(v1.begin() + 1, v1.end(), 0) - v1.begin();
    if(t != n + 1) return cout << "NO\n1" << " " << t << '\n', 0;
    dfs(1, G2, v2);
    t = find(v2.begin() + 1, v2.end(), 0) - v2.begin();
    if(t != n + 1) return cout << "NO\n"<< t << " " << 1 << '\n', 0;
    return cout << "YES\n", 0;  
}