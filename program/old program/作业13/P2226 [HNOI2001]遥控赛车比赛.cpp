/*
#include <iostream>
#include<queue>
using namespace std;
#define maxn 105
int map[maxn][maxn], x1, y1, x2, y2, n, m, fx[4] = { -1,0,1,0 }, fy[4] = { 0,-1,0,1 }, bj[maxn][maxn], ans[maxn][maxn],over[maxn][maxn];
struct node
{
	int x, y, s;
};
queue<node>a;
node temp;
void debug() 
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
			printf("%3d",map[i][j]);
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	for (int i = 1; i <= 10; i++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				bj[i][j] = over[i][j]=0;
				ans[i][j] = -1;
			}
		ans[x1][y1] = 0;
		temp.x = x1;
		temp.y = y1;
		temp.s = 0;
		a.push(temp);
		while (!a.empty())
		{
			bj[a.front().x][a.front().y] = 1;
			ans[a.front().x][a.front().y] = a.front().s;
			for (int j = 0; j < 4; j++)
			{
				int X = a.front().x + fx[j], Y = a.front().y + fy[j], S = a.front().s + 1;
				bool gameover = false;
				for (int q = 1; q <= i; q++)
				{
					int xx = a.front().x + q * fx[j], yy = a.front().y + q * fy[j];
					if (xx > 0 && yy > 0 && xx <= n && yy <= n)
						if (!map[xx][yy])
						{
							gameover = true;
							break;
						}
				}
				if (gameover == false)
				{
					for (int q = 1; q <= i; q++)
					{
						int xx = a.front().x + q * fx[j], yy = a.front().y + q * fy[j];
						if (xx > 0 && yy > 0 && xx <= n && yy <= n)
							over[xx][yy] = 1;
					}
				}
				if (X > 0 && Y > 0 && X <= n && Y <= m && (bj[X][Y] == 0 || S < map[X][Y]) && over[X][Y]==1 &&map[X][Y]==1)
				{
					temp.x = X;
					temp.y = Y;
					temp.s = S;
					a.push(temp);
				}
			}
			a.pop();
		}
		if (ans[x2][y2] == -1)
			return 0;
		cout << i << " " << ans[x2][y2] << endl;
	}
	return 0;
}
*/