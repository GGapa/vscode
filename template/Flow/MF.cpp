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