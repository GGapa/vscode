/**
 * @Problem      : P1265 公路修建
 * @URL          : https://www.luogu.com.cn/problem/P1265
 * @Author       : GGapa
 * @Date         : 2023-11-16 21:10:44
 * @LastEditTime : 2023-11-16 22:00:18
**/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 5000 + 5;

int n;
double x[maxn], y[maxn], dis[maxn], vis[maxn], ans;

double get_e(double x1,double y1,double x2,double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Prim()
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double ,int>>> q;
	int curr;
	double mi;
    q.push(make_pair(0.0, 1));
    while(!q.empty())
	{
		curr = q.top().second; q.pop();
        if(vis[curr]) continue;
		vis[curr] = true;
		ans += dis[curr];
		for(int j = 1;j <= n; j++) if(dis[j] > get_e(x[curr], y[curr], x[j], y[j]))
			dis[j] = get_e(x[curr], y[curr], x[j], y[j]), q.push(make_pair(dis[j], j));
	}
	printf("%.2lf",ans);
	return ;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", 'w', stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        dis[i] = 1e12;
    }
    dis[1] = 0;
    Prim();
    return 0;
}   