/*
#include <iostream>
#include <queue>
using namespace std;
#define maxn 101
char map[maxn][maxn];
bool bj[maxn][maxn] = { 0 };
int fx[4] = { 1,-1,0,0 }, fy[4] = { 0,0,-1,1 };
queue<int> x;
queue<int> y;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	x.push(1);
	y.push(1);
	bj[1][1] = 1;
	while (!x.empty()) {
		for (int i = 0; i < 4; i++) {
			int X = x.front() + fx[i];
			int Y = y.front() + fy[i];
			if (X > 0 && Y > 0 && X <= n && Y <= m && map[X][Y] == '.' && bj[X][Y] == false) {
				x.push(X);
				y.push(Y);
				bj[X][Y] = 1;
			}
		}
		x.pop();
		y.pop();
	}
	if (bj[n][m])cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
*/