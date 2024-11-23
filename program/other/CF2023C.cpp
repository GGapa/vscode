#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int ma; cin >> ma;
    vector<vector<array<int, 2>>> adj1(n + 1), adj2(n + 1);
    for(int i = 1, u, v; i <= ma; i++)  {
        cin >> u >> v;
        adj1[u].push_back({v, 1});
        adj1[v].push_back({v, k - 1});
    }

    vector<int> b(n + 1);
    rep(i, 1, n) cin >> b[i];
    int mb; cin >> mb;
    for(int i = 1, u, v; i <= mb; i++) {
        cin >> u >> v;
        adj2[u].push_back({v, 1});
        adj2[v].push_back({u, k - 1});
    }

    queue<int> q;
    vector<int> fa(n + 1, -1);
    q.push(1); fa[1] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : adj1[x]) {
            int to = i[0], w = i[1];
            if(fa[to] != -1) continue;
            fa[to] = (fa[x] + w) % k;
            q.push(to);
        }
    }

    vector<int> fb(n + 1, -1);
    q.push(1); fb[1] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : adj2[x]) {
            int to = i[0], w = i[1];
            if(fb[to] != -1) continue;
            fb[to] = (fb[x] + w) % k;
            q.push(to);
        }
    }

    int ca = count(a.begin() + 1, a.end(), 0);
    int cb = count(b.begin() + 1, b.end(), 1);

    if(ca != cb) return cout << "NO\n", void();
    if(ca == 0 || ca == n) return cout << "YES\n", void();

    vector<int> s(k), t(k);
    rep(i, 1, n) {
        if(a[i] == 1) {
            fa[i] = (fa[i] + 1) % k;
            s[fa[i]] += n;
        }
        else {
            fa[i] = (fa[i] + k - 1) % k;
            s[fa[i]] += 1;
        }
        if(b[i] == 1) t[fb[i]] += 1;
        else t[fb[i]] += n;
    }

    s.insert(s.begin(), -2);
    s.emplace_back(-1);
    s.insert(s.end(), t.begin(), t.end());
    s.insert(s.end(), t.begin(), t.end());

    vector<int> kmp(s.size() + 1);  
    for(int i = 2, j = 0; i < s.size(); i++) {
        while(j && s[i] != s[j + 1]) j = kmp[j];
        if(s[i] == s[j + 1]) j++;
        kmp[i] = j;
        if(j == k) return cout << "YES\n", void();
 
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}   