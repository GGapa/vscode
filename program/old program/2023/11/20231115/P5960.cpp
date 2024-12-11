/**
 * @Problem      : P5960 【模板】差分约束
 * @URL          : https://www.luogu.com.cn/problem/P5960
 * @Author       : GGapa
 * @Date         : 2023-11-15 09:53:13
 * @LastEditTime : 2023-11-15 10:15:49
**/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 5e3 + 5;

int n, m;
vector<pair<int, int>> G[maxn];
int dis[maxn], vis[maxn], cnt[maxn];

bool spfa() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        dis[i] = 2e9;
        vis[i] = 0;
    }
    q.push(0);
    dis[0] = 0; vis[0] = 1; cnt[0] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop(); vis[x] = 0;
        for(auto i : G[x]) {
            int to = i.first, val = i.second;
            if(dis[to] > dis[x] + val) {
                dis[to] = dis[x] + val;
                if(vis[to] == 0) {
                    vis[to] = 1;
                    q.push(to);
                    cnt[to]++;
                    if(cnt[to] > n + 1) return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v, w;  i<= m; i++) {
        cin >> u >> v >> w;
        G[v].push_back(make_pair(u, w));
    }
    for(int i = 1; i <= n; i++) G[0].push_back(make_pair(i, 0));
    if(!spfa()) {
        for(int i = 1; i <= n; i++) {
            cout << dis[i] << ' ';
        }
    }
    else cout << "NO\n";
    return 0;
}
