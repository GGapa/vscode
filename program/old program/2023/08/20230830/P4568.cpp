/*
P4568 [JLOI2011] 飞行路线
https://www.luogu.com.cn/problem/P4568
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
const int maxn = 110000 + 10;

int n, m, k;
int s, t;
vector<int> nxt[maxn], v[maxn];
int dist[maxn];
int vis[maxn];

void Dijkstra(int n, int S) {
    memset(dist, 0x3f, sizeof(dist));
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > q;
    q.push(make_pair(0, S));
    while(!q.empty()) {
        int now = q.top().second;
        q.pop();
        if(vis[now]) continue;   
        for(int i = 0; i < nxt[now].size(); i++) {
            int cur = nxt[now][i];
            if(dist[cur] > dist[now] + v[now][i]) {
                dist[cur] = dist[now] + v[now][i];
                q.push(make_pair(dist[cur], cur));
            }
        }
    }
}

void addedge(int x, int y, int z) {
    nxt[x].push_back(y);
    v[x].push_back(z);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    cin >> s >> t;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = 0; j < k; j++) {
            addedge(j * n + a, (j + 1) * n + b, 0);
            addedge(j * n + b, (j + 1) * n + a, 0);
        }
        for(int j = 0; j <= k; j++) {
            addedge(j * n + a, j * n + b, c);
            addedge(j * n + b, j * n + a, c);
        }
    }
    Dijkstra((k + 1) * n, s);
    int ans = INT_MAX;
    for(int i = 0; i <= k; i++) {
        ans = min(ans, dist[i * n + t]);
    }
    cout << ans << endl;
    return 0;
}