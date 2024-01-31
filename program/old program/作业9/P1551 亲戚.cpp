/*
#include <iostream>
using namespace std;

int n, m, p, a[5004];

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
	int x, y;
	for (int i = 1; i <= 5003; i++)
	{
		a[i] = i;
	}
	cin >> n >> m >> p;
	for (int i = 0; i < m; i++)
	{
		cin >> x>> y;
		add(x, y);
	}
	for (int i = 0; i < p; i++)
	{
		cin >> x >> y;
		if (find(x) == find(y))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}
*/