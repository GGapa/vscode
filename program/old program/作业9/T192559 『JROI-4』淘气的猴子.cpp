/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, m, a[1000], b[201][3];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i][0] >> b[i][1] >> b[i][2];
	}
	for (int i = m - 1; i >= 0; i--)
	{
		if (b[i][0] == 1)
		{
			if (b[i][1] - 1 == b[i][2] - 1)
			{
				a[b[i][1] - 1] *= 0.5;
			}
			else a[b[i][1]-1] -= a[b[i][2]-1];
		}
		if (b[i][0] == 2)
		{
			if (b[i][1] - 1 == b[i][2] - 1)
				a[b[i][1] - 1] =sqrt(a[b[i][1] - 1]);
			else a[b[i][1]-1] /= a[b[i][2]-1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
*/