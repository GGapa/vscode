/*
Mall Mania
https://vjudge.csgrandeur.cn/contest/584212#problem/C
2023-10-04
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2005;
#define int long long

int n, m;
int shop1[maxn][maxn], shop2[maxn][maxn];
struct node {
    int x, y, step;
};
queue<node> Q;

int fx[5] = {0, -1, 1, 0, 0};
int fy[5] = {0, 0, 0, -1, 1};

int bfs() {
    while(!Q.empty()) {
        node now = Q.front();
        Q.pop();
        int nx = now.x, ny = now.y, ns = now.step;
        if(shop2[nx][ny]) return ns;// 如果能到达
        for(int i = 1; i <= 4; i++) {
            int xx = nx + fx[i], yy = ny + fy[i];
            if(xx < 1 || xx > 2000 || yy <1 || yy > 2000 || shop1[xx][yy]) continue;
  			shop1[xx][yy] = 1;
  			Q.push((node){xx, yy, ns + 1});
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n != 0) {
        while(!Q.empty())Q.pop();
        memset(shop1, 0, sizeof(shop1));
        memset(shop2, 0, sizeof(shop2));
        int x, y;
        for(int i = 1; i <= n; i++) {
            cin >> x >> y ;
            Q.push(node{x, y, 0});
            shop1[x][y] = 1;
        }
        cin >> m;
        for(int i = 1; i <= m; i++) {
            cin >> x >> y;
            shop2[x][y] = 1;
        }
        cout << bfs() << "\n";
        cin >> n;
    }
    
    return 0;
}