/*
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define maxn 8
char map[maxn][maxn];
int ifpush[maxn][maxn];
void print()
{
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
			cout << !ifpush[i][j];
		cout << endl;
	}
}
void car(int x, int y)
{
	int temp;
	ifpush[x][y] = 1;
	temp = x;
	while (--temp >= 0 && map[temp][y] == '.')ifpush[temp][y] = 1;
	temp = x;
	while (++temp < maxn && map[temp][y] == '.')ifpush[temp][y] = 1;
	temp = y;
	while (++temp < maxn && map[x][temp] == '.')ifpush[x][temp] = 1;
	temp = y;
	while (--temp >= 0 && map[x][temp] == '.')ifpush[x][temp] = 1;
}
void quee(int x, int y)
{
	int xx, yy;
	ifpush[x][y] = 1;
	xx = x;
	yy = y;
	while (--xx >= 0 && --yy >= 0 && map[xx][yy] == '.')ifpush[xx][yy] = 1;
	xx = x;
	yy = y;
	while (--xx >= 0 && ++yy < maxn && map[xx][yy] == '.')ifpush[xx][yy] = 1;
	xx = x;
	yy = y;
	while (++xx < maxn && ++yy < maxn && map[xx][yy] == '.')ifpush[xx][yy] = 1;
	xx = x;
	yy = y;
	while (++xx < maxn && --yy >= 0 && map[xx][yy] == '.')ifpush[xx][yy] = 1;
}
int main()
{
	memset(ifpush, 0, sizeof(ifpush));
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			cin >> map[i][j];
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			if (map[i][j] == 'R')
				car(i, j);
			if (map[i][j] == 'B')
				quee(i, j);
		}
	}
	print();
	return 0;
}
*/