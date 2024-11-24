/*
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define maxn 200000
int n, m, a[maxn];
struct city
{
	int l, r, t;
}b[maxn];
bool cmd(city x, city y)
{
	return x.t < y.t;
}
int find(int x)
{
	return x == a[x] ? x : (a[x] = find(a[x]));
}
void add(int x, int y)
{
	int X = find(x);
	int Y = find(y);
	if (X != Y)
	{
		n--;
		a[X] = Y;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)a[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> b[i].l >> b[i].r >> b[i].t;
	sort(b + 1, b + m + 1, cmd);
	for (int i = 1; i <= m; i++)
	{
		add(b[i].l, b[i].r);
		if (n == 1)
		{
			cout << b[i].t << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
*/