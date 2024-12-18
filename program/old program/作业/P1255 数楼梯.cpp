/*
#include <iostream>
using namespace std;

int a[6000][2000], Long = 0;

void jia(int i)
{
	bool bj = false;
	for (int j = 0; j < 2000; j++)
	{
		Long++;
		a[i][j] += a[i - 1][j] + a[i - 2][j];
		if (a[i][j] >= 10)
		{
			a[i][j + 1] += 1;
			a[i][j] -= 10;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	a[0][0] = 1;
	a[1][0] = 2;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < 6000; j++)
		{
			a[i][j] = 0;
		}
		Long = 0;
		jia(i);
	}
	int bj = false;
	for (int i = Long-1; i >=0; i--)
	{
		if (a[n - 1][i] != 0)
			bj = true;
		if(bj)
			cout << a[n - 1][i];
	}
	cout << endl;
	return 0;
}
*/