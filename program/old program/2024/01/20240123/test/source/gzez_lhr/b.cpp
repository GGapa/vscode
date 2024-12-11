#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define _rev(i, u) for(int i = head[u]; i; i = e[i].nxt)
#define pb push_back
#define fi first
#define se second
#define mst(f, i) memset(f, i, sizeof f)
using namespace std;
#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif
typedef long long ll;
typedef pair<int, int> PII;
namespace fastio{
    char ibuf[50007],*p1 = ibuf, *p2 = ibuf;
    #ifdef ONLINE_JUDGE
    #define get() p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 50007, stdin), p1 == p2) ? EOF : *p1++
    #else
    #define get() getchar()
    #endif
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = getchar();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = getchar();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args&... args){
        read(t);
        read(args...);
    }
    template<typename T> void write(T t){
        if(t < 0) putchar('-'), t = -t;
        if(t >= 10) write(t / 10);
        putchar(t % 10 + '0');
    }
    template<typename T, typename ... Args> void write(T t, Args... args){
        write(t), putchar(' '), write(args...);
    }
    template<typename T> void writeln(T t){
        write(t);
        puts("");
    }
    template<typename T> void writes(T t){
        write(t), putchar(' ');
    }
    #undef get
};
using namespace fastio;
#define multitest() int T; read(T); _rep(tCase, 1, T)
namespace Calculation{
    const ll mod = 1e9 + 7;
    ll ksm(ll p, ll h){ll base = p % mod, res = 1; while(h){if(h & 1ll) res = res * base % mod; base = base * base % mod, h >>= 1ll;} return res;}
    void dec(ll &x, ll y){x = ((x - y) % mod + mod) % mod;}
    void add(ll &x, ll y){x = (x + y) % mod;}
    void mul(ll &x, ll y){x = x * y % mod;}
    ll sub(ll x, ll y){return ((x - y) % mod + mod) % mod;}
    ll pls(ll x, ll y){return ((x + y) % mod + mod) % mod;}
    ll mult(ll x, ll y){return x * y % mod;}
}
using namespace Calculation;
const int N = 805;
ll pw[N], inv[N];
ll C(ll n, ll m){
    if(n < m) return 0;
    if(n == m || !m) return 1;
    return pw[n] * inv[m] % mod * inv[n - m] % mod;
}
int n, n1, n2, m, fa1[N], fa2[N], d1[N], d2[N], t1[N], t2[N];
int lg[N];
struct edge{
    int v, w, t;
};
vector<edge> G1[N], G2[N];
ll f[N][N], sum[N][N];
set<int> st;
void update(){
    mst(f, 0), f[0][0] = 1;
    _rep(i, 1, n){
        _rep(j, 0, n){
            for(auto &k : st) if(j >= k) add(f[i][j], f[i - 1][j - k] % mod);
        }
    }
}
void add(int k){
    _req(i, n, 1){
        _req(j, n, 0){
            _rep(p, 1, j / k){
                if(i >= p) add(f[i][j], f[i - p][j - k * p] * C(i, p) % mod);
            }
        }
    }    
}
void del(int k){
    _rep(i, 1, n){
        _rep(j, 0, n){
            _rep(p, 1, j / k){
                if(i >= p) dec(f[i][j], f[i - p][j - k * p] * C(i, p) % mod);
            }
        }
    }
}
ll ans;
void solve(int u1, int u2){
    if(G1[u1].size() != G2[u2].size()) return ans = 0, void();
    _rep(i, 0, (int)G1[u1].size() - 1){
        int v1 = G1[u1][i].v, v2 = G2[u2][i].v, w1 = G1[u1][i].w, w2 = G2[u2][i].w;
        solve(v1, v2);
        if(!ans) return;
        if(w1 > w2) return ans = 0, void();
        mul(ans, f[w1][w2]);
    }
}
int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    read(n1, n2), n = max(n1, n2);
    pw[0] = inv[0] = 1, lg[0] = -1;
    _rep(i, 1, n) lg[i] = lg[i >> 1] + 1, pw[i] = pw[i - 1] * i % mod, inv[i] = ksm(pw[i], mod - 2);
    _rep(i, 2, n1) read(fa1[i]), d1[fa1[i]]++;
    _rep(i, 2, n2) read(fa2[i]), d2[fa2[i]]++;
    queue<int> q; _rep(i, 1, n1) if(!d1[i]) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop();
        int v = fa1[u], w = 1, lst = u; while(d1[v] == 1) lst = v, v = fa1[v], w++;
        G1[v].pb({u, w, lst});
        if(++t1[v] == d1[v]) q.push(v);
    }
    _rep(i, 1, n2) if(!d2[i]) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop();
        int v = fa2[u], w = 1, lst = u; while(d2[v] == 1) lst = v, v = fa2[v], w++;
        G2[v].pb({u, w, lst});
        if(++t2[v] == d2[v]) q.push(v);
    }
    _rep(i, 0, n1) sort(G1[i].begin(), G1[i].end(), [](edge x, edge y){return x.t < y.t;});
    _rep(i, 0, n2) sort(G2[i].begin(), G2[i].end(), [](edge x, edge y){return x.t < y.t;});
    read(m);
    f[0][0] = 1;
    while(m--){
        int opt, x; read(opt, x);
        if(opt == 2) st.erase(x), del(x);
        else st.insert(x), add(x);
        ans = 1;
        solve(0, 0);
        writeln(ans);
    }
    return 0;
}

