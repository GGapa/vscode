#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 400000 + 5;

int n, tp;  

namespace work1 {
    int vis[N], cnt[3];
    vector<int> G[N];

    void dfs(int x) {
        cnt[vis[x]]++;
        for(auto to : G[x]) if(!vis[to]) vis[to] = 3 - vis[x], dfs(to);
    }

    void solve() {    
        cin >> n;
        vector<int> A(n + 1), B(n + 1);
        rep(i, 1, n) cin >> A[i];
        rep(i, 1, n) cin >> B[i];
        rep(i, 1, 2 * n) G[i].clear(), vis[i] = 0;
        rep(i, 1, n) G[A[i]].emplace_back(B[i] + n), G[B[i] + n].emplace_back(A[i]);
        int ans = 0;
        vis[0] = 1;
        rep(i, 1, 2 * n) if(!vis[i]) {
            cnt[1] = cnt[2] = 0;
            vis[i] = 1;
            dfs(i);
            ans += min(cnt[1], cnt[2]);
        }
        cout << ans << '\n';
    }
}

namespace work2 {
    vector<array<int, 2>> G[N];
    set<int> G1[N];
    vector<int> stk;
    int dfn[N], low[N];
    set<int> s;            
    int ct1[N][3], ct2[N][3];   // 分别是没有限制，和不经过隔边的
    int be1[N], be2[N], sz1[N], sz2[N];
    int vis[N], belong[N];
    int ans, sum;

    void dfs(int x, int id) {
        ct1[id][vis[x]]++; be1[x] = id;
        for(auto i : G[x]) {
            int to = i[0];
            if(vis[to]) continue;
            vis[to] = 3 - vis[x];
            dfs(to, id);
        }
    }
    void dfs1(int x, int fa) {
        vis[x] = 1;
        for(auto to : G1[x]) if(to != fa && !vis[to]) {
            dfs1(to, x);
            ans = min(ans, sum - min(ct1[be2[x]][1], ct1[be2[x]][2]) + min(ct2[to][1], ct2[to][2]) + min(ct1[be2[x]][1] - ct2[to][1], ct1[be2[x]][2] - ct2[to][2]));
            ct2[x][1] += ct2[to][1];
            ct2[x][2] += ct2[to][2];
        }
    }
    void tarjan(int x, int fa) {
        low[x] = dfn[x] = ++dfn[0];
            stk.emplace_back(x);
        for(auto i : G[x]) {
            int to = i[0], it = i[1];    
            if (it == (fa ^ 1)) continue;  
            if(!dfn[to]) {
                tarjan(to, it);
                low[x] = min(low[x], low[to]);
            }
            else low[x] = min(low[x], dfn[to]);
        }
        if(dfn[x] == low[x]) {
            ++belong[0];
            for(int i = -1; i != x; stk.pop_back()) 
                belong[(i = stk.back())] = belong[0];
        }
    }

    void solve() {
        cin >> n;
        vector<int> A(n + 1), B(n + 1);
        rep(i, 1, n) cin >> A[i];
        rep(i, 1, n) cin >> B[i];
        rep(i, 0, 2 * n + 2) G[i].clear(), G1[i].clear(), vis[i] = dfn[i] = low[i] = ct1[i][2] = ct1[i][1] = ct2[i][1] = ct2[i][2] = be1[i] = be2[i] = sz1[i] = sz2[i] = belong[i] = 0;
        stk.clear();
        rep(i, 1, n) G[A[i]].push_back({B[i] + n, i * 2}), G[B[i] + n].push_back({A[i], i * 2 + 1});

        ans = 0, sum = 0;
        dfn[0] = 0; s.clear(); ct1[0][0] = ct2[0][0] = 0;
        rep(i, 1, 2 * n) if(!vis[i]) {
            vis[i] = 1;
            ++ct1[0][0];
            ct1[ct1[0][0]][1] = ct1[ct1[0][0]][2] = 0;
            dfs(i, ct1[0][0]);
            ans += min(ct1[ct1[0][0]][1], ct1[ct1[0][0]][2]);
        }
        sum = ans;

        rep(i, 1, 2 * n) if(!dfn[i]) tarjan(i, 0);
        rep(i, 1, 2 * n) for(auto j : G[i]) if(belong[i] != belong[j[0]]) 
            G1[belong[i]].insert(belong[j[0]]);
        rep(x, 1, n) ct2[belong[x]][1]++;
        rep(x, n + 1, n * 2) ct2[belong[x]][2]++;
        rep(i, 1, 2 * n) be2[belong[i]] = be1[i];

        fill(vis, vis + 1 + 2 * n, 0);
        rep(i, 1, n * 2) if(!vis[i]) dfs1(i, 0);
        cout << max(ans, 1) << '\n';
    }
}

namespace work3 {
	multiset<int> s;
    int vis[N], lsz[N], rsz[N], col[N], ins[N], dfn[N], low[N], stk[N];
    int tim, top;
    vector<int> G[N];
    vector<array<int, 2>> E[N];

    void dfs(int u) {
        vis[u] = 1, lsz[u] = (u <= n), rsz[u] = lsz[u] ^ 1;
        for (int v : G[u]) if (!vis[v])
            dfs(v), lsz[u] += lsz[v], rsz[u] += rsz[v];
    }
	int query(int x) {
		if (x < 0) return -max(x, *s.begin());
		if (x > 0) return min(x, *(--s.end()));
		return x;
	}
	int ans = 0, tot = 0;
	void tarjan(int u, int fa, int R) {
		dfn[u] = low[u] = ++tim, stk[++top] = u, ins[u] = 1;
		for (auto i : E[u]) {
            int v = i[0], w = i[1];
            if ((w ^ fa) == 0) continue;
            if (!dfn[v])
                tarjan(v, w, R), low[u] = min(low[u], low[v]);
            else if (ins[v])
                low[u] = min(low[u], dfn[v]);
        }
		if (low[u] ^ dfn[u]) return ans = max(ans, tot + query(rsz[R] - lsz[R])), void();
		
		while(1) {
			int v = stk[top--];
			ins[v] = 0, col[v] = u;
			if (u == v) break;
		}
		if (R == u) return;
		int tmp = min(lsz[R], rsz[R]) - min(lsz[u], rsz[u]) - min(lsz[R] - lsz[u], rsz[R] - rsz[u]);
        ans = max(ans, tot - tmp + query(rsz[u] - lsz[u]));
		ans = max(ans, tot - tmp + query((rsz[R] - rsz[u]) - (lsz[R] - lsz[u])));
	}
	void solve() {
        tim = top = 0;
        rep(i, 1, n << 1) col[i] = ins[i] = dfn[i] = low[i] = stk[i] = 0;
        rep(i, 1, n << 1) vis[i] = 0, G[i].clear(), E[i].clear(), lsz[i] = rsz[i] = 0;
		ans = tot = 0, s.clear();

        cin >> n;
        vector<int> A(n + 1), B(n + 1);
        rep(i ,1, n) cin >> A[i];
        rep(i ,1, n) cin >> B[i], B[i] += n ;
        rep(i, 1, n) G[A[i]].emplace_back(B[i]), G[B[i]].emplace_back(A[i]), E[A[i]].push_back({B[i], i}), E[B[i]].push_back({A[i], i});

		if (n == 1) return cout << 1 << '\n', void();
		rep(i, 1, n << 1) vis[i] = 1;
		rep(i, 1, n) vis[A[i]] = vis[B[i]] = 0;
		rep(i, 1, n) if (vis[i]) s.insert(1);
		rep(i, n + 1, n << 1) if(vis[i]) s.insert(-1);
		rep(i, 1, n) if (!vis[i]) dfs(i), tot += min(lsz[i], rsz[i]), s.insert(lsz[i] - rsz[i]);
		ans = tot;
        
		rep(i, 1, n) if (!dfn[i] && !G[i].empty()) {
			s.erase(s.find(lsz[i] - rsz[i]));
            tarjan(i, 0, i);
			s.insert(lsz[i] - rsz[i]);
		}     
        cout << ans << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T >> tp;
    if(tp == 0  ) while(T--) work1::solve();
    else if(tp == 1) while(T--) work2::solve();
    else while(T--) work3::solve();
    return 0;
}
/*
1 1
8
1 1 2 1 5 1 5 1
2 5 6 1 4 4 8 7
*/