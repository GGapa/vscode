/*
#include <iostream>
#include <cstdio>
using namespace std;

long long f[25][25][25];


long long w(long long a, long long b, long long c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	else if (f[a][b][c] != 0)
	{
		return f[a][b][c];
	}
	else if (a < b && b < c)
	{
		f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	return f[a][b][c];
}


int main()
{
	long long x[9999], y[9999], z[9999];
	for(int i = 0;i<9999;i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		if (x[i] == -1 && y[i] == -1 && z[i] == -1)break;
	}
	for (int i = 0; i < 9999; i++)
	{
		if (x[i] == -1 && y[i] == -1 && z[i] == -1)break;
		cout << "w(" << x[i] << ", " << y[i] << ", " << z[i] << ") = " << w(x[i], y[i], z[i]) << endl;
	}
	return 0;
}
*/