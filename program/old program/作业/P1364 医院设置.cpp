/*
#include <iostream>
using namespace std;
#define maxn 101


struct node_
{
	int father = 0, left = 0, right = 0, population = 0, rank;
};

node_ node[maxn];
int s[maxn][maxn] = { 0 }, far1[maxn] = { 0 }, far2[maxn] = { 0 };
int farn = 1, farn2 = 0, far=0,n;
long long an=0,man=999999999999999;
void re1(int x)
{
	far1[farn] = node[x].father;
	if (x == 0)
		return;
	if(node[x].father!=0)farn++;
	re1(node[x].father);
}
void re2(int x)
{

	for (int i = 0; i <= farn; i++)
	{
		if (node[x].father == far1[i]&&x!=0)
		{
			far += (i);
			return;
		}
	}
	if (x == 0)
		return;
	farn2++;
	re2(node[x].father);
}
void ans(int x)
{
	if (node[x].left + node[x].right == 0)
		return;
	for (int i = 1; i <= n; i++)
	{
		an += s[i][x];
	}
	man = min(man, an);
	an = 0;
	if (node[x].left != 0)ans(node[x].left);
	if(node[x].right!=0)ans(node[x].right);
}
int main()
{
	int  w, u, v;
	node[1].father = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> u >> v;
		node[i].population = w;
		node[i].left = u;
		node[i].right = v;
		if (u != 0)node[node[i].left].father = i;
		if (v != 0)node[node[i].right].father = i;
	}

	for (int i = 1; i <=n; i++)
	{
		for (int q = 0; q < maxn; q++)
			far1[q] = 0;
		farn = 1;
		far1[0] = i;
		re1(i);
		for (int j = i; j <=n; j++)
		{
			farn2 = far = 0;
			farn2++;
			re2(j);
			if(i!=j)s[i][j] = (far + farn2) * node[i].population;
			if(i!=j)s[j][i] = (far + farn2) * node[j].population;
		}
	}
	ans(1);
	cout << man << endl;
	return 0;
}
*/