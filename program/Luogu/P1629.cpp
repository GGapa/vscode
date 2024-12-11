/**
 * @Problem      : P1629 邮递员送信
 * @URL          : https://www.luogu.com.cn/problem/P1629
 * @Author       : GGapa
 * @Date         : 2023-11-15 09:25:17
 * @LastEditTime : 2023-11-15 09:34:45
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e3 + 5;

int n, m;
int dis[maxn];

void Dijkstra(vector<pair<int, int>> G[maxn]) {
    for(int i = 1; i <=  n; i++) dis[i] = 1e9;
    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> q;
    dis[1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        int x = q.top().second;
        q.pop();
        for(auto i : G[x]) {
            int to = i.first, val = i.second;
            if(val + dis[x] >= dis[to]) continue;
            q.push(make_pair(val + dis[x], to));
            dis[to] = val + dis[x];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopne("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m;
    vector<pair<int, int>> G1[maxn], G2[maxn];
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G1[u].push_back(make_pair(v, w));
        G2[v].push_back(make_pair(u, w));
    }
    long long ans = 0;
    Dijkstra(G1);
    for(int i = 2; i <= n; i++) ans += dis[i];
    Dijkstra(G2);
    for(int i = 2; i <= n; i++) ans += dis[i];
    cout << ans << '\n';
    return 0;
}