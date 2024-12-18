/*
#include <iostream>
#include <queue>
using namespace std;
const auto maxn = 105;
struct node_
{
	int father, left, right, rank;
};
node_ node[maxn];
int mdeep = 0, a[maxn] = { 0 }, mwide = 0, up[maxn] = { 0 }, down[maxn] = { 0 }, s = 0;
void re1(int x, int y)
{
	node[x].rank = y;
	if (x != 0)a[node[x].rank]++;
	if (node[x].left == 0 && node[x].right == 0)
		return;

	y++;
	mdeep = max(mdeep, y);
	re1(node[x].left, y);
	re1(node[x].right, y);
}
void re2(int x, int y)
{
	if (node[x].father == 1)
	{
		up[y] = 1;
		return;
	}
	up[y] = node[x].father;
	re2(node[x].father, y + 1);
}
void re3(int x, int y)
{
	if (node[x].father == 1)
	{
		down[y] = 1;
		return;
	}
	down[y] = node[x].father;
	re3(node[x].father, y + 1);
}
int main()
{
	int n, x, y;
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int ls;
		cin >> ls;
		if (node[ls].left == 0)
			cin >> node[ls].left;
		else
			cin >> node[ls].right;
		node[node[ls].left].father = ls;
		node[node[ls].right].father = ls;
	}
	node[1].father = 1;
	cin >> x >> y;
	re1(1, 1);
	for (int i = 0; i < maxn; i++)
		mwide = max(mwide, a[i]);
	up[0] = x;
	re2(x, 1);
	down[0] = y;
	re3(y, 1);
	for (int i = 0; i < maxn; i++)
	{
		bool bj = false;
		for (int j = 0; j < maxn; j++)
		{
			if (up[i] == down[j] && up[i] * down[j] != 0)
			{
				s = (i) * 2 + j;
				bj = true;
				break;
			}
		}
		if (bj)
			break;
	}
	cout << mdeep << endl << mwide << endl << s << endl;
	return 0;
}
*/