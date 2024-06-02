// Plan of Lectures
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 3e5 + 5;

vector<int> G2[N], G[N];
vector<int> G1[N];
int A[N], F[N], in[N], vis[N];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    // vector<int> A(n + 1), F(n + 1), in(n  +1), vis(n + 1);
    queue<int> q;
    rep(i, 1, n) {
        cin >> A[i];
        G1[A[i]].push_back(i); in[i]++;
        F[i] = i;
    }
    function<int(int)> find = [&](int x) {return F[x] == x ? x : F[x] = find(F[x]);};
    for(int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
		G2[x].push_back(y); G1[x].push_back(y); in[y]++;
		if(find(x) == y){
			cout << "0\n";
			return 0;
		}
		F[y] = x;
    }
    // vector<int> dep(n + 1), s(n  +1);
    // function<void(int)> dfs = [&](int x) {
    //     s[dep[x]] = x;
    //     for(auto y : G2[x]) if(dep[y] < dep[x] && s[dep[y]] == y) {
    //         cout << "0\n";
    //         exit(0);
    //     }
    //     for(auto to : G1[x]) {
    //         dep[to] = dep[x] + 1;
    //         dfs(to);
    //     }
    // };
    // dfs(0);
    // int cnt = 0;
    q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        // cnt++;
        // for(int to = x; to; to = (G2[to].empty() ? 0 : G2[to][0])) ans.push_back(to);
        for(auto to : G1[x]) if(!--in[to]) q.push(to);
    }
    rep(i, 1, n) if(in[i] != 0) return cout << "0\n", 0;
    function<void(int)> dfs = [&](int x) {
        vis[x] = 1;
        for(auto to : G1[x]) {
            if(vis[to] == 1) {
                cout << "0\n";
                exit(0);
            }
            if(vis[to] == 0) dfs(to);
        }
        vis[x] = 2;
    };
    dfs(0);
    // rep(i, 1, n)
    // in.assign(n + 1, 0);
    rep(i, 1, n) in[i] = 0;
    rep(i, 1, n) {
        int u = find(A[i]), v = find(i);
        if(u != v) {
            G[u].push_back(v);
            in[v]++;
        }
    }
    vector<int> ans;
    q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int to = x; to; to = (G2[to].empty() ? 0 : G2[to][0])) ans.push_back(to);
        for(auto to : G[x]) if(!--in[to]) q.push(to);
    }
    if(ans.size() != n) return cout << "0\n", 0;
    for(auto a : ans) cout << a << ' ';\
    return 0;   
}