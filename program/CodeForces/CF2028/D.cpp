#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1), C(n + 1), vis(n + 1), va(n + 1), vb(n + 1), vc(n + 1);
    vector<pair<char, int>> pre(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qa, qb, qc;
    priority_queue<int, VI, greater<int>> q;
    rep(i, 1, n) cin >> A[i], qa.emplace(A[i], i), va[i] = A[i];
    rep(i, 1, n) cin >> B[i], qb.emplace(B[i], i), vb[i] = B[i];
    rep(i, 1, n) cin >> C[i], qc.emplace(C[i], i), vc[i] = C[i];
    q.emplace(1); 
    while(!q.empty()) {
        int x = q.top(); q.pop();
        auto work = [&](priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &qq, char op, vector<int> &vv) {
            while(!qq.empty() && qq.top().first < vv[x]) {
                int t = qq.top().second;
                if(!vis[t] && t > x) {
                    q.push(t);
                    vis[t] = 1;
                    pre[t] = {op, x};
                }
                qq.pop();
            }
        };  
        work(qa, 'q', va);
        work(qb, 'k', vb);
        work(qc, 'j', vc);
    }
    if(!vis[n]) return cout << "NO\n", void();
    cout << "YES\n";
    vector<pair<int, int>> ans;
    for(int i = n; i != 1; ) {
        ans.emplace_back(pre[i].first, i);
        i = pre[i].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto a : ans) cout << (char)a.first << " " << a.second << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}