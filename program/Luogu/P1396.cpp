/**
 * @Problem      : P1396 营救
 * @URL          : https://www.luogu.com.cn/problem/P1396
 * @Author       : GGapa
 * @Date         : 2023-11-16 10:19:00
 * @LastEditTime : 2023-11-16 10:35:12
**/

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>z`
using namespace std;
const int maxn = 1e4 + 5;
typedef pair<int, int> pii;

int n, m, s, t;
vector<pii> G[maxn];
int dis[maxn];

void Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i = 1; i <= n; i++) dis[i] = 1e9;
    q.push(make_pair(0, s)); dis[s] = 0;
    while(!q.empty()) {
        int x = q.top().second; q.pop();
        for(auto i : G[x]) {
            int to = i.first, w = i.second;
            int _ = max(w, dis[x]);
            if(_ >= dis[to]) continue;
            dis[to] = _;
            q.push(make_pair(_, to));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m >> s >> t;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    Dijkstra();
    cout << dis[t] << '\n';
    return 0;
}