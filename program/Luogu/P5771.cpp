#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

namespace LS {
    constexpr int N = 1e5 + 5;
    int pri[N], phi[N], mi[N], mu[N];
    bitset<N> vis;

    void init(){
        mu[1] = 1;
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i, mi[i] = i, phi[i] = i - 1, mu[i] = -1;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                mi[tt] = pri[j];
                if(i % pri[j] == 0) {
                    phi[tt]  = phi[i] * pri[j];
                    break;
                }
                else phi[tt] = phi[i] * phi[pri[j]];
                mu[tt] = -mu[i];
            }
        }
    }
}using LS::vis;


int n, m, s, t;
namespace MF {
    constexpr int N = 3000 + 5, M = N * N;
    int tot = 1, head[M], cur[M];
    int dep[M];

    struct edge {
        int v, nxt;
        LL val;
    }e[M * 2];

    void add(int u, int v, LL w) {
        e[++tot].v = v;
        e[tot].val = w;
        e[tot].nxt = head[u];
        head[u] = tot;
        
        e[++tot].v = u;
        e[tot].val = 0;
        e[tot].nxt = head[v];
        head[v] = tot;
    }

    int bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(dep));
        q.push(s);
        dep[s] = 1;
        cur[s] = head[s];
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].v;
                if(e[i].val > 0 && !dep[v]) {
                    q.push(v);
                    cur[v] = head[v];
                    dep[v] = dep[u] + 1;
                    if(v == t) return 1;
                }
            }
        }
        return dep[t];
    }

    int dfs(int u, LL sum) {
        if(u == t || !sum) return sum;
        LL k, res = 0;
        for(int i = cur[u]; i && sum; i = e[i].nxt) {
            int v = e[i].v;
            cur[u] = i;
            if(e[i].val > 0 && dep[v] == dep[u] + 1) {
                k = dfs(v, min(sum, e[i].val));
                if(k == 0) dep[v] = 0;
                e[i].val -= k;
                e[i^1].val += k;
                res += k;
                sum -= k;
            }
        }
        return res;
    }
    LL work() {
        LL ans = 0;
        while(bfs())  ans += dfs(s, LLONG_MAX);
        return ans;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LS::init();
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    sort(A.begin() + 1, A.end(), greater<>());
    if(A.back() == 1) {
        while(A.back() == 1) A.pop_back();
        A.emplace_back(1);
    }

    rep(i, 1, n) rep(j, 1, n) if(i != j && (A[i] & 1) && !(A[j] & 1) && !vis[A[i] + A[j]])
        MF::add(i, j, 1e9);
    s = 0; t = n + 1;
    rep(i, 1, n) if(A[i] & 1) MF::add(s, i, 1);
    rep(i, 1, n) if(!(A[i] & 1)) MF::add(i, n + 1, 1);

    cout << n - MF::work() << '\n';
    return 0;
}