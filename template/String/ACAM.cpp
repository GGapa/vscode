#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e5 + 5;

int tr[N][26], fail[N], sum[N], idx = 0;
int ed[N];
vector<int> G[N];

int insert(const string &s) {
    int it = 0;
    for(auto c : s) {
        auto &f = tr[it][c - 'a'];
        if(!f) f = ++idx;
        it = f;
    }
    return it;
}

void bfs() {
    queue<int> q;
    rep(i, 0, 25) if(tr[0][i]) q.emplace(tr[0][i]);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        rep(i, 0, 25) {
            if(tr[x][i]) {
                fail[tr[x][i]] = tr[fail[x]][i];
                q.push(tr[x][i]);
            }
            else tr[x][i] = tr[fail[x]][i];
        }
    }
}

void dfs(int x) {
    for(auto to : G[x]) {
        dfs(to), sum[x] += sum[to];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n) {
        string s; cin >> s;
        ed[i] = insert(s);
    }
    bfs();
    rep(i, 1, idx) G[fail[i]].emplace_back(i);
    string t; cin >> t;
    {
        int it = 0;
        for(auto c : t) {
            auto &f = tr[it][c - 'a'];
            it = f;
            sum[it]++;
        }
    }
    dfs(0);
    // rep(i, 1, idx) if(sum[i]) cout << i << '\n';
    rep(i, 1, n) cout << sum[ed[i]] << '\n';
    return 0;
}