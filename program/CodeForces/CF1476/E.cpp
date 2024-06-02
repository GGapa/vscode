#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    unordered_map<string, int> mp;
    vector<string> A(n + 1);
    vector<VI> G(n + 1);
    vector<int> in(n + 1);
    auto check = [&](string &x, string &y) {
        rep(i, 0, k) if(x[i] != '_' && x[i] != y[i] && y[i] != '_' ) return false;
        return true;
    };
    rep(i, 1, n) cin >> A[i], mp[A[i]] = i;
    rep(i, 1, m) {
        int p; string s;
        cin >> s >> p;
        if(!check(A[p], s)) return cout << "NO\n", 0; 
        rep(t, 0, (1 << k) - 1) {
            string c = s;
            rep(j, 0, k) if(t & (1 << j)) c[j] = '_';
            // cout << c << '\n';
            if(mp.count(c) != 0 && mp[c] != p) G[p].emplace_back(mp[c]), in[mp[c]]++;
        }
    }
    
    queue<int> q;
    vector<int> ans;
    rep(i, 1, n) if(!in[i]) q.push(i);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        ans.emplace_back(x);
        for(auto to : G[x]) if(--in[to] == 0) q.emplace(to);
    }
    if(ans.size() != n) return cout << "NO\n", 0;
    cout << "YES\n";
    for(auto i : ans) cout << i << " ";
    return 0;
}