#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 100000 + 5;

vector<int> G[N], al[N];
int n;
int vis[N], tp[N];
int idx = 0, cnt = 0, ans = 0;

void dfs(int x, int fa) {
    for(auto to : G[x]) if(to != fa) dfs(to, x);
    if(!vis[x] && !vis[fa]) vis[x] = vis[fa] = 1, cnt++;   
    if(!vis[x]) al[idx].push_back(x);
}

int fa[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("hidden.in", "r", stdin);
    // freopen("hidden.out", "w", stdout);
    cin >> n;
    rep(i ,2, n) {
        cin >> fa[i];
        G[fa[i]].push_back(i);
    }
    vis[0] = 1;
    rep(x, 1, n) if(!fa[x]) {
        tp[++idx] = x;
        dfs(x, cnt = 0) ;
        ans += cnt; 
    }
    vector<int> id(idx + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 2, id.end(),[&](const int &x, const int &y) {
        return al[x].size() > al[y].size();
    });
    auto lt = al[id[1]];
    rep(t, 2, idx) {
        int i = id[t];
        if(vis[tp[i]]) fa[tp[i]] = 1;
        else {
            while(!lt.empty() && vis[lt.back()]) lt.pop_back();
            if(!lt.empty()) vis[fa[tp[i]] = lt.back()] = vis[tp[i]] = 1, ans++;
            else fa[tp[i]] = 1;
        }
        for(auto ad : al[i]) lt.push_back(ad);
    }
    cout << ans << '\n';
    rep(i, 2, n) cout << fa[i] << " \n"[i == n];
    return 0;
} 