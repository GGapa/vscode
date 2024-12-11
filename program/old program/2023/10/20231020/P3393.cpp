#include <iostream>
#include <vector>
#include <limits.h>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define int long long
const int maxn = 100000 + 500;

int n, m, k, s;
int p, q;
int a[maxn];
int c[maxn];
long long dis[maxn];
vector<int> G[maxn];
bool used[maxn];
queue<pair<int, int> > bq;

void bfs() {
    while(!bq.empty())    {
        int x = bq.front().first, step = bq.front().second;
        bq.pop();
        if(step == 0) a[x] = 30000000000;
        else a[x] = q;
        if(step >= s) continue;
        for(auto to : G[x]) {
            if(a[to] == 0) {
                bq.push(make_pair(to, step + 1));
            }
        }
    }
}

void Dijkstra() {
    for(int i = 1; i <= n; i++) dis[i] = 30000000000;
    priority_queue<pair<int, int>, vector<pair<int ,int > >, greater<pair<int, int> > > q;
    q.push(make_pair(0, 1));
    dis[1] = 0;
    while(!q.empty()) {
        int x = q.top().second; q.pop();
        if(used[x]) continue;
        used[x] = true;
        for(auto to : G[x]) {
            if(a[to] != LLONG_MAX && dis[x] + a[to]  < dis[to]) {
                dis[to] = dis[x] + a[to];
                q.push(make_pair(dis[to], to));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s;
    cin >> p >> q;
    for(int i = 1, c; i <= k; i++) cin >> c, bq.push(make_pair(c, 0)), used[c] = true;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs();
    for(int i = 2; i < n; i++) if(a[i] == 0) a[i] = p;
    a[1] = a[n] = 0;
    Dijkstra() ;
    cout << dis[n] << "\n";
    return 0;
}