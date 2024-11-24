/*
#include <iostream>
using namespace std;

int n, m, a[10005], z, x, y,boos;

int find(int x)
{
	if (a[x] == x)
	{
		return x;
	}
	return a[x] = find(a[x]);
}
void add(int x, int y)
{
	a[find(x)] = find(y);
}


int main()
{
	for (int i = 0; i < 10000; i++)
	{
		a[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> z >> x >> y;
		if (z == 1)
		{
			add(x, y);
		}
		if (z == 2)
		{
			if (find(x) == find(y))
			{
				cout << "Y" << endl;
			}
			else
			{
				cout << "N" << endl;
			}
		}
	}
	return 0;
}
*/