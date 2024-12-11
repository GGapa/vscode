/**
 * @Problem      : P2865 [USACO06NOV] Roadblocks G
 * @URL          : https://www.luogu.com.cn/problem/P2865
 * @Author       : GGapa
 * @Date         : 2023-11-15 11:08:59
 * @LastEditTime : 2023-11-15 11:34:36
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5000 + 5;

int n, m;
vector<pair<int, int>> G[maxn];
int dis[3][maxn];

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for(int i = 1; i <= n; i++) dis[1][i] = dis[0][i] = 1e9;
    dis[0][1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        int x = q.top().second, val = q.top().first;
        q.pop();
        if(val > dis[1][x]) continue;
        for(auto i : G[x]) {
        int to = i.first, w = i.second;
            if(dis[0][to] > val + w) {
                dis[1][to] = dis[0][to];
                dis[0][to] = val + w;
                q.push(make_pair(dis[0][to], to));
            }
            if(dis[1][to] > val + w && dis[0][to] < val + w) {
                dis[1][to] = val + w;
                q.push(make_pair(dis[1][to], to));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    Dijkstra();
    cout << dis[1][n] << '\n';
    return 0;
}