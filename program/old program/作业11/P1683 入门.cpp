/*
#include <iostream>
using namespace std;
#define maxn 51
int fx[4] = { 0,-1,0,1 },fy[4] = {-1,0,1,0};
char a[maxn][maxn];
int bj[maxn][maxn];
int ans = 1,w, h;
void dfs(int x,int y)
{
	bool bj_ = true;
	for (int i = 0; i < 4; i++)
	{
		if (x + fx[i] >= 0 && x + fx[i] < h && y + fy[i] >= 0 && y + fy[i] < w)
		{
			if (!bj[x + fx[i]][y + fy[i]]&&a[x + fx[i]][y + fy[i]]!='#')
			{
				bj_ = false;
				break;
			}
		}
	}
	if (bj_)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (x + fx[i] >= 0 && x + fx[i] < h && y + fy[i] >= 0 && y + fy[i] < w)
		{
			if ((a[x + fx[i]][y + fy[i]] == '.'|| a[x + fx[i]][y + fy[i]] == '@')&&!bj[x + fx[i]][y + fy[i]])
			{
				ans++;
				bj[x + fx[i]][y + fy[i]] = true;
				dfs(x + fx[i], y + fy[i]);
			}
		}
	}

}
int main()
{
	int x1,y1;
	cin >> w >> h;
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			bj[i][j] = false;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '@')
			{
				x1 = i;
				y1 = j;
			}
		}
	}
	bj[x1][y1] = true;
	dfs(x1, y1);
	cout << ans << endl;
	return 0;
	ans = 0;
}
*/