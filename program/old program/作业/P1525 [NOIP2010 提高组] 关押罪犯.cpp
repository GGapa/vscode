/*
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, m, f[20005], e[20005];
struct peo
{
	int x, y, z;
}a[100005];
bool so(peo x, peo y)
{
	return x.z > y.z;
}
int rela[20005] = { 0 }, ans = 0;
int find(int x)
{
	return f[x] == x ? x : (f[x] = find(f[x]));
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)f[i] = f[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	sort(a + 1, a + 1 + m, so);
	for (int i = 1; i <= m + 1; i++)
	{
		if (find(a[i].x) == find(a[i].y))
		{
			cout << a[i].z << endl;
			return 0;
		}
		if (!e[a[i].x])e[a[i].x] = a[i].y;
		else f[find(e[a[i].x])] = find(a[i].y);
		if (!e[a[i].y])e[a[i].y] = a[i].x;
		else f[find(e[a[i].y])] = find(a[i].x);
	}
	return 0;
}
*/