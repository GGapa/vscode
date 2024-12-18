/*
#include <iostream>
#include <vector>
using namespace std;
int a[50005], n, m, ans = 0;
vector<int>E[50005];
vector<int>F[50005];
bool bj[50001] = { false };
int find(int x)
{
	if (a[x] == x)return x;
	return a[x] = find(a[x]);
}
int finde(int x)
{
	if (a[x] == x)return x;
	bj[x] = true;
	find(a[x]);
}
void addf(int x, int y)
{
	int a1 = find(x), b1 = find(y);
	if (a1 != b1)a[a1] = b1;
}
void adde(int x)
{
	int a1 = find(x);
	for (int i = 0; i < E[a1].size() - 1; i++)
	{
		a[find(E[a1][i])] = find(E[a1][i + 1]);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= 50001; i++)
		a[i] = i;
	for (int i = 1; i <= m; i++)
	{
		char opt;
		int p, q;
		cin >> opt;
		cin >> p >> q;
		if (opt == 'F')
		{
			F[p].push_back(q);
			F[q].push_back(p);
		}
		if (opt == 'E')
		{
			E[p].push_back(q);
			E[q].push_back(p);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < F[i].size(); j++)
		{
			addf(i, F[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < E[i].size() - 1 && E[i].size() != 0; j++)
		{
			a[find(E[i][j])] = find(E[i][j + 1]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (bj[i] == true)
			continue;
		int f = find(i);
		bj[i] = true;
		ans++;
		for (int j = 1; j <= n; j++)
		{
			if (find(j) == f)
				bj[j] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
*/