#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<LL , 3>;
const int N = 300000 + 5;
const LL INF = 1e18;

vector<AI> G[N];

struct Dijkstra {
    int n; vector<LL> dis; vector<array<LL, 2>> pre;
    LL& operator[] (const int x) {return dis[x]; }
    Dijkstra() {}
    Dijkstra(int _n) : n(_n), dis(_n + 1, INF), pre(_n + 1, {-1, -1}) { }
    void init(int nn) {n = nn, dis.assign(n + 1, INF); pre.assign(n + 1, {-1, -1}); }
    void work(int st) {
        priority_queue<AI, vector<AI>, greater<AI>> q;
        fill(dis.begin(), dis.end(), INF);
        dis[st] = 0; q.push({0, st});
        while(!q.empty()) {
            int x = q.top()[1], w = q.top()[0]; q.pop();
            if(dis[x] < w) continue;
            for(auto i : G[x]) {
                int to = i[0], w = i[1];
                if(dis[to] > dis[x] + w) {
                    dis[to] = dis[x] + w;
                    pre[to] = {x, i[2]};
                    q.push({dis[to], to});
                }
            }   
        }
    }
}dj1, dj2;

LL ans[N];

#define ls (x << 1)
#define rs ((x << 1) | 1)
namespace SGT {
    int n;
    LL tr[N << 2];
    void init(int nn) {n = nn; fill_n(tr, N << 2, INF); } 
    void modify(int L, int R, LL v, int x = 1, int l = 1, int r = n) {
        if(l > r) return;
        if(L <= l && r <= R) return tr[x] = min(tr[x], v), void();
        int mid = l + r >> 1;
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
    }
    void update(int x = 1, int l = 1, int r = n) {
        if(l > r) return;
        if(l == r) return ans[l] = tr[x], void();
        tr[ls] = min(tr[ls], tr[x]); tr[rs] = min(tr[rs], tr[x]);
        int mid = l + r >> 1;
        update(ls, l, mid); 
        update(rs, mid + 1, r);
    }
}
#undef rs
#undef ls
using SGT::tr;

int n, m;
vector<int> path(1);
int l[N], r[N], id[N];   // debug id 这里应当对所有元素记录。

void bfs(int st, vector<LL> &dis, int *tgt) {
    queue<int> q;
    q.push(path[st]); tgt[path[st]] = st;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : G[x]) {
            int to = i[0], w = i[1];
            if(dis[x] + w == dis[to] && id[to] == 0 && tgt[to] == 0) {
                tgt[to] = st;
                q.push(to);
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> in(m + 1), mx(m + 1);          // 太厉害了，数组开小了，我真牛，逆天，连续开小了两次，真的是服了
    multiset<int> s; vector<int> W(1);
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w, i}) ,G[v].push_back({u, w, i}), s.insert(w), W.emplace_back(w);

    rep(i, 1, m - 1) {
        s.erase(s.find(W[i]));
        mx[i] = *s.rbegin();
    }
    
    rep(i, 1, n) reverse(G[i].begin(), G[i].end());
    dj1.init(n), dj2.init(n);
    dj1.work(1), dj2.work(n);

    for(int x = 1; ; ) {
        id[x] = path.size();
        path.emplace_back(x);
        if(x == n) break;
        in[dj2.pre[x][1]] = 1;
        x = dj2.pre[x][0];
    }

    int mm = path.size() - 1; 
    rep(i, 1, mm) bfs(i, dj1.dis, l);
    per(i, mm, 1) bfs(i, dj2.dis, r);

    SGT::init(mm - 1);
    rep(x, 1, n) for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(l[x] >= r[to] || l[x] == 0 || in[i[2]] || r[to] == 0) continue;
        SGT::modify(l[x], r[to] - 1, dj1[x] + w + dj2[to]);
    }
    SGT::update();

    int mn = 0, cnt = 0;
    rep(i, 1, mm - 1) {
        if(ans[i] > mn) mn = ans[i], cnt = 1;
        else if(ans[i] == mn) cnt++;
    }
    if(mn == dj1[n]) cnt = m;
    cout << mn  <<  ' ' << cnt << '\n';
    return 0 ;

    return 0 ;
}
/*
1000000000000000000
1000000000000000000
*/