namespace MF {
    struct E {
        int v; LL w;
        E(int v = 0, LL w = 0) : v(v), w(w) {}
    };
    vector<E> e;
    vector<int> G[N];
    void addE(int u, int v, LL w) {
        G[u].emplace_back(e.size());
        e.emplace_back(v, w);
    }
    int add(int u, int v, LL w) {
        addE(u, v, w); addE(v, u, 0);
        return (int)e.size() - 2;
    }

    int n = -1;
    int dep[N], cur[N];
    void init(int nn) {n = nn; }
    bool bfs(int s, int t) {
        fill(dep, dep + 1 + n, 0);
        queue<int> q;
        dep[s] = 1; q.push(s);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(auto i : G[x]) {
                auto [to, w] = e[i];
                if(!dep[to] && w) {
                    dep[to] = dep[x] + 1;
                    q.emplace(to);
                }
            }
        }
        return dep[t];
    }
    LL dfs(int x, int t, LL in) {
        if(x == t) return in;
        LL out = 0;
        for(int &i = cur[x]; i < G[x].size(); i++) {
            int id = G[x][i];
            auto [to, w] = e[id];
            if(dep[to] == dep[x] + 1 && w) {
                LL f = dfs(to, t, min(in - out, w));
                out += f;
                e[id].w -= f; e[id ^ 1].w += f;
                if(out == in) return out;
            } 
        }
        if(!out) dep[x] = 0;
        return out;
    }
    LL work(int s, int t) {
        assert(n != -1);
        LL ret = 0;
        while(bfs(s, t)) {
            fill(cur, cur + 1 + n, 0);
            ret += dfs(s, t, 1e18);
        }
        return ret;
    }
}
using namespace MF;